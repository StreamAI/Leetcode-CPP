/*
 * @lc app=leetcode.cn id=147 lang=c
 *
 * [147] 对链表进行插入排序
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* insertionSortList(struct ListNode* head){
    if(head == NULL || head->next == NULL)
        return head;

    struct ListNode* dummyHead = malloc(sizeof(struct ListNode));
    dummyHead->next = head;

    struct ListNode* lastSorted = head;
    struct ListNode* curr = lastSorted->next;
    while (curr != NULL)
    {
        if(curr->val >= lastSorted->val){
            lastSorted = lastSorted->next;
            curr = lastSorted->next;
        } else {
            lastSorted->next = curr->next;

            struct ListNode* prev = dummyHead;
            while (curr->val >= prev->next->val && prev->next != lastSorted)
                prev = prev->next;
            curr->next = prev->next;
            prev->next = curr;
            
            curr = lastSorted->next;
        }
    }

    head = dummyHead->next;
    free(dummyHead);

    return head;
}
// @lc code=end

