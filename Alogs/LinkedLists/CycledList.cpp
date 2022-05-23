/*
A single linked may have a cycle where in which it will start over when reached.
return true if it cycles.
strategy is to loop a fast and slow node and return true if they equal each other or false if the lead null hits a nullptr.
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        //if(!head) return false;
        ListNode* l = head, *l1=head;
          if(!l || !l->next || !l->next->next)return false;
        
        l=l->next->next;
        l1=l1->next;
        
        while(head!=l || head!=l1 || l!=l1){
    if(!l || !l->next || !l->next->next) return false;
          l1=l1->next->next;
          l=l->next->next->next;
          head=head->next;
        }
        return l1;
    }
};
