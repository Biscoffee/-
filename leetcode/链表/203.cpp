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
        ListNode* removeElements(ListNode* head, int val) {
            ListNode* temp = head;
            ListNode* prev = nullptr;
            while(temp && temp->val==val){   //为什么用while，因为可能存在多个值为val的头节点
                head = temp->next;
                delete(temp);
                temp = head;
            }
            while (temp && temp->next) { // 修正：val 而不是 data
                if(temp-> val == val){
                    prev->next = temp->next;
                    delete(temp);
                    temp = prev->next;   //更新temp
                }else{
                    prev = temp;
                    temp = temp->next;
                }
            }
            return head;
        }
    };
    class Solution {
        public:
            ListNode* removeElements(ListNode* head, int val) {
                // 处理头节点为 val 的情况
                while (head && head->val == val) {
                    ListNode* temp = head;
                    head = head->next;
                    delete temp; // 释放内存
                }
        
                // 处理其他节点为 val 的情况
                ListNode* curr = head;
                while (curr && curr->next) {
                    if (curr->next->val == val) {
                        ListNode* temp = curr->next;
                        curr->next = curr->next->next;
                        delete temp; // 释放内存
                    } else {
                        curr = curr->next;
                    }
                }
        
                return head; // 返回更新后的链表头节点
            }
        };