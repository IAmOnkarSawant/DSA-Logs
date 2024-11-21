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
    ListNode* merge(ListNode* H1, ListNode* H2)
    {
        // if(H1 == NULL)
        //     return H2;
        // if(H2 == NULL)
        //     return H1;

        ListNode* curr = NULL, *head = NULL;
        while(H1 && H2)
        {
            if(H1->val < H2->val)
            {
                if(!head) {head = H1; curr = head;}
                else
                {
                    curr->next = H1;
                    curr = curr->next;
                }
                H1 = H1->next;
            }
            else
            {
                if(!head) {head = H2; curr = head;}
                else
                {
                    curr->next = H2;
                    curr = curr->next;
                }
                H2 = H2->next;
            }
        }
        if(H1)
        {
            curr->next = H1;
        }
        if(H2)
        {
            curr->next = H2;
        }
        return head;
    }

    ListNode* sortList(ListNode* head) 
    {
        if(head == NULL || head->next == NULL)
            return head;

        ListNode* slow = head, *fast = head, *prev = NULL;
        while(fast != NULL && fast->next != NULL)
        {
            prev = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        if(prev)
            prev->next = NULL;  //=====================forgot

        ListNode* t1 = head; 
        ListNode* t2 = slow; 
        // while(head)
        // {
        //     cout<<head->val;
        //     head = head->next;
        // }
        // cout<<"\n";

        // while(slow)
        // {
        //     cout<<slow->val;
        //     slow = slow->next;
        // }

        ListNode* temp1 = sortList(t1);
        ListNode* temp2 = sortList(t2);
        return merge(temp1, temp2);
        // return NULL;
    }
};