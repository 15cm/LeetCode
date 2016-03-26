/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} n
 * @return {ListNode}
 */
var removeNthFromEnd = function(head, n) {
    'use strict';
    var start = new ListNode(0);
    var slow = start, fast = start;
    slow.next = head;
    while(n--){
        fast = fast.next;
    }
    while(fast.next !== null){
        slow = slow.next;
        fast = fast.next;
    }
    slow.next = slow.next.next;
    return start.next;
};
