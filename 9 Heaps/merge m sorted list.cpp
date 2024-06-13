/*
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
*/
 class compare{
     public:
        bool operator()(ListNode*a,ListNode*b){
            
            return a->val > b->val;
        }
    };
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

       
        vector<int>arr;
        if(lists.size()==0){
            return nullptr;
        }
        for(int i=0;i<lists.size();i++){
            ListNode*temp=lists[i];
            while(temp!=nullptr){
                arr.push_back(temp->val);
                temp=temp->next;
            }
        }
        sort(arr.begin(),arr.end());
        ListNode*head=nullptr;
        ListNode*tail=nullptr;
        for(int i=0;i<arr.size();i++){
            ListNode*top= new ListNode(arr[i]);
            if(head==nullptr){
                head=top;
                tail=top;
            }
            else{
                tail->next=top;
                tail=top;
            }
        }
        return head;
    }
};