class Solution {
public:
/*Initially all users are online
for events message whosever id is mentioned is online at that particular timestamp
for events offline whoseever id is mentioned is offline at that particular timestamp
the user can come online only after timestamp + 60 units of time not before that 
Explanation:
Initial Setup:
Users: id0 and id1.
Initially, both users are online.
Mentions array: [0, 0] (no mentions yet).
Event 1: ["MESSAGE", "10", "id1 id0"]:
At timestamp 10, a message mentions id0 and id1.
Each mention is counted:
id0 is mentioned once → [1, 0].
id1 is mentioned once → [1, 1].
Mentions after this event: [1, 1].
Event 2: ["OFFLINE", "11", "0"]:
At timestamp 11, id0 goes offline.
The current status:
id0: Offline.
id1: Online.
No mentions occur in this event.
Mentions remain: [1, 1].
Event 3: ["MESSAGE", "71", "HERE"]:
At timestamp 71, id0 automatically comes back online (offline duration ends after 60 time units from timestamp 11).
"HERE" mentions all currently online users.
Both id0 and id1 are online.
Each user is mentioned once more:
id0 → [2, 1].
id1 → [2, 2].
Mentions after this event: [2, 2].


Explanation:
Initial Setup:
Users: id0 and id1.
Initially, both users are online.
Mentions array: [0, 0] (no mentions yet).
Event 1: ["MESSAGE", "10", "id1 id0"]:
At timestamp 10, a message mentions id0 and id1.
Each mention is counted:
id0 is mentioned once → [1, 0].
id1 is mentioned once → [1, 1].
Mentions after this event: [1, 1].
Event 2: ["OFFLINE", "11", "0"]:
At timestamp 11, id0 goes offline.
The current status:
id0: Offline.
id1: Online.
No mentions occur in this event.
Mentions remain: [1, 1].
Event 3: ["MESSAGE", "12", "ALL"]:
At timestamp 12, "ALL" mentions all users, regardless of whether they are online or offline.
Each user is mentioned once more:
id0 → [2, 1].
id1 → [2, 2].
Mentions after this event: [2, 2]

Explanation:
Initial Setup:
Users: id0 and id1.
Initially, both users are online.
Mentions array: [0, 0] (no mentions yet).
Event 1: ["OFFLINE", "10", "0"]:
At timestamp 10, id0 goes offline.
The current status:
id0: Offline.
id1: Online.
No mentions occur in this event.
Mentions remain: [0, 0].
Event 2: ["MESSAGE", "12", "HERE"]:
At timestamp 12, "HERE" mentions only the currently online users.
At this time:
id0 is still offline and is not mentioned.
id1 is online and is mentioned once.
Mentions array is updated:
id0 remains unmentioned → [0, 0].
id1 is mentioned once → [0, 1].
Mentions after this event: [0, 1].*/

    static bool cmp(vector<string>a, vector<string>b) {
        int timeA = stoi(a[1]);
        int timeB = stoi(b[1]);
        //if the timestamp is same then sort it like offline should come first then msg i.e., compare lexicographically or according to one with less timeStamp
        return timeA == timeB ? a[0] > b[0] : timeA < timeB;
    }

    void handleMessage(vector<string>event, vector<int>&mentions, vector<int>&offlineTime) {
        int timestamp = stoi(event[1]);
        vector<string>ids;
        //collecting all ids separated by space
        stringstream s(event[2]);
        string word;
        // The >> operator extracts the next word from the stringstream and stores it in the variable word.
        while(s >> word) {
            ids.push_back(word);
        }

        for(auto it: ids) {
            if(it == "ALL") {
                for(int i=0; i<mentions.size(); i++) {
                    mentions[i]++;
                }
            }
            else if(it == "HERE") {
                for(int i=0; i<mentions.size(); i++) {
                    if(offlineTime[i] == 0 || offlineTime[i] + 60 <= timestamp) {
                        mentions[i]++;
                    }
                }
            }
            else {
                //id0 se 0 extract kr rha aur 0 ko integer me convert kr rha
                int idNum = stoi(it.substr(2));
                mentions[idNum]++;
            }
        }
    }

    void handleOffline(vector<string>event, vector<int>&mentions, vector<int>&offlineTime) {
        int timestamp = stoi(event[1]);
        int id = stoi(event[2]);
        offlineTime[id] = timestamp;
    }

    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int>mentions(numberOfUsers);
        vector<int>offlineTime(numberOfUsers);
        //sort according to timestamp 
        sort(events.begin(), events.end(), cmp);
        for(auto it: events) {
            if(it[0] == "MESSAGE") {
                handleMessage(it, mentions, offlineTime);
            }
            else if(it[0] == "OFFLINE") {
                handleOffline(it, mentions, offlineTime);
            }
        }
        return mentions;
    }
};