/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} k
 * @return {ListNode}
 */
var rotateRight = function(head, k) {
    'use strict';
    if(head === null || head.next === null ) return head;
    var fast = head, slow = head;
    var n;
    for(n = 1; fast.next !== null; n ++) fast = fast.next;
    for(let j = n - k % n; j > 1; j --) slow = slow.next;
    fast.next = head;
    head = slow.next;
    slow.next = null;
    return head;
};
