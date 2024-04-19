/**
 * 1. Multiple Datastructures
 *    postTweet - O(1)
 *      maintain hash of userId and LL pointer with new tweet being head
 *      Insertion of tweet can be done in O(1) this way
 *    getNewsFeed - O(10log10) ~ O(1)
 *      find all possible tweet list using following map and current userId
 *      run mergeKSortedLL using Heap until heap is empty or maxTweets limit not reached
 *    follow and unfollow - O(logn)
 *      maintain hash of userId and set having userIds
 *      Insert and remove will be O(logn) in set
*/

#include <bits/stdc++.h>

using namespace std;

#define FEED_TWEET_COUNT 10

class Tweet
{
public:
  int userId;
  int tweetId;
  int timestamp;

public:
  Tweet(int userId, int tweetId, int timestamp) {
    this->userId = userId;
    this->tweetId = tweetId;
    this->timestamp = timestamp;
  }
};

class TweetNode
{
public:
  Tweet* tweet;
  TweetNode* next;

public:
  TweetNode(Tweet* tweet) {
    this->tweet = tweet;
    this->next = nullptr;
  }
};

struct GreaterTweet {
  bool operator()(TweetNode* a, TweetNode* b) {
    return a->tweet->timestamp < b->tweet->timestamp;
  }
};

class Twitter {
  unordered_map<int, set<int>> following;
  unordered_map<int, TweetNode*> userTweets;
  int timestamp;

public:
  Twitter() {
    this->timestamp = 0;
  }

  void postTweet(int userId, int tweetId) {
    Tweet* tweet = new Tweet(userId, tweetId, timestamp);
    timestamp++;

    TweetNode* tweetNode = new TweetNode(tweet);

    if (userTweets[userId]) {
      TweetNode* tailTweet = userTweets[userId];
      tweetNode->next = tailTweet;
    }

    userTweets[userId] = tweetNode;
  }

  vector<int> getNewsFeed(int userId)
  {
    // Head pointers to Linked lists
    vector<TweetNode*> allPossibleTweets;

    for (auto it = following[userId].begin(); it != following[userId].end(); it++) {
      if (userTweets[*it]) {
        allPossibleTweets.push_back(userTweets[*it]);
      }
    }

    if (userTweets[userId]) {
      allPossibleTweets.push_back(userTweets[userId]);
    }

    priority_queue<TweetNode*, vector<TweetNode*>, GreaterTweet> maxTweetTimestampHeap;
    vector<int> tweets;

    int n = allPossibleTweets.size();
    for (TweetNode* tweetNode: allPossibleTweets) {
      maxTweetTimestampHeap.push(tweetNode);
    }

    while (tweets.size() < FEED_TWEET_COUNT && maxTweetTimestampHeap.size()) {
      TweetNode* mostRecentTweet = maxTweetTimestampHeap.top();

      tweets.push_back(mostRecentTweet->tweet->tweetId);

      maxTweetTimestampHeap.pop();

      mostRecentTweet = mostRecentTweet->next;
      if (mostRecentTweet) {
        maxTweetTimestampHeap.push(mostRecentTweet);
      }
    }

    return tweets;
  }

  void follow(int followerId, int followeeId) {
    following[followerId].insert(followeeId);
  }

  void unfollow(int followerId, int followeeId) {
    following[followerId].erase(followeeId);
  }
};

void printVector(vector<int> nums)
{
  for (int x: nums) {
    cout << x << " ";
  }
  cout << endl;
}

void solution()
{
  // Twitter twitter = Twitter();
  // twitter.postTweet(1, 5); // User 1 posts a new tweet (id = 5).
  // printVector(twitter.getNewsFeed(1));  // User 1's news feed should return a list with 1 tweet id -> [5]. return [5]
  // twitter.follow(1, 2);    // User 1 follows user 2.
  // twitter.postTweet(2, 6); // User 2 posts a new tweet (id = 6).
  // printVector(twitter.getNewsFeed(1));  // User 1's news feed should return a list with 2 tweet ids -> [6, 5]. Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
  // twitter.unfollow(1, 2);  // User 1 unfollows user 2.
  // printVector(twitter.getNewsFeed(1));

  Twitter twitter;
  twitter.postTweet(1, 1);
  printVector(twitter.getNewsFeed(1));
  twitter.follow(2, 1);
  printVector(twitter.getNewsFeed(2));
  twitter.unfollow(2, 1);
  printVector(twitter.getNewsFeed(2));
}

int main()
{
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    solution();
  }

  return 0;
}
