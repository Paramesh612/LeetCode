/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int findLen(ListNode* head){
        int c=0;
        while(head!=NULL){
            head=head->next;
            c++;
        }
        return c;
    }
    vector<int> nextLargerNodes(ListNode* head) {
        stack<pair<int,int>> st;
        ListNode *temp=head;
        int indexArb=0;
        vector<int>ans(findLen(head));

        while(temp!=NULL){
            while(!st.empty() && temp->val>st.top().first){
                ans[st.top().second]=temp->val;
                st.pop();
            }
            st.push({temp->val,indexArb++});
            temp=temp->next;
        }
        return ans;   
    }
};