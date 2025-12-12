class Solution {
    private class OfflineEntry {
        int offlineTill;
        int userId;
        
        public OfflineEntry(int time, int id) {
            offlineTill = time;
            userId = id;
        }
    }

    public int[] countMentions(int numberOfUsers, List<List<String>> events) {
        Collections.sort(events, new Comparator<List<String>>() {
            @Override
            public int compare(List<String> e1, List<String> e2){
                int eventTime1 = Integer.parseInt(e1.get(1));
                int eventTime2 = Integer.parseInt(e2.get(1));
                
                // status change should be prior
                if (eventTime1 == eventTime2) {
                    String status1 = e1.get(0);
                    if("OFFLINE".equals(status1)) return -1;

                    String status2 = e2.get(0);
                    if("OFFLINE".equals(status2)) return 1;

                    return 0;
                }

                return eventTime1 - eventTime2;
            }
        });     

        int allMentions = 0;
        List<Integer> mentions = new ArrayList<>(Collections.nCopies(numberOfUsers, 0));
        Set<Integer> offlineUsers = new HashSet<>();
        PriorityQueue<OfflineEntry> offlineTimer = new PriorityQueue<>(new Comparator<OfflineEntry>() {
            @Override
            public int compare(OfflineEntry e1, OfflineEntry e2) {
                return e1.offlineTill - e2.offlineTill;
            }
        });

        // process the events
        for (List<String> event : events) {

            System.out.println(event);


            String type = event.get(0);
            // int timestamp = (int)Integer.getInteger(event.get(1));
            int timestamp = Integer.parseInt(event.get(1) );
            String payload = event.get(2);

            if ("OFFLINE".equals(type)) {
                int uid = Integer.parseInt(payload);
                // bandaid
                if (offlineUsers.contains(uid)) {
                    List<OfflineEntry> temp = new ArrayList<>();
                    while (offlineTimer.peek().userId != uid) {
                        temp.add(offlineTimer.poll());
                    }
                    OfflineEntry item = offlineTimer.poll();
                    item.offlineTill = timestamp + 60;
                    offlineTimer.add(item);

                    for (int i=0; i<temp.size(); i++) {
                        offlineTimer.add(temp.get(i));
                    }
                }
                else{
                    offlineUsers.add(uid);
                    offlineTimer.add(new OfflineEntry(timestamp + 60, uid));
                }
            }
            else {
                // System.out.println("MESSAGE ");
                // online users first
                while (!offlineTimer.isEmpty() &&
                        offlineTimer.peek().offlineTill <= timestamp) {
                    OfflineEntry entry = offlineTimer.poll();
                    offlineUsers.remove(entry.userId);
                }

                if ("ALL".equals(payload)) allMentions++;
                else if ("HERE".equals(payload)) {
                    for (int i=0; i<numberOfUsers; i++) {
                        if (!offlineUsers.contains(i)) mentions.set(i, mentions.get(i) + 1);
                    }
                }
                else {
                    String[] userIds = payload.split(" ");
                    for (String userId : userIds) {
                        System.out.println("userID " + userId);
                        int id = Integer.parseInt(userId.substring(2));
                        mentions.set(id, mentions.get(id) + 1);
                    }
                }
            }
        }

        for (int i=0; i<mentions.size(); i++) mentions.set(i, mentions.get(i) + allMentions);
        return mentions.stream()
                       .mapToInt(Integer::intValue)
                       .toArray();
        }
}