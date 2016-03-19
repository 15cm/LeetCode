/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
    'use strict';
    var l = new ListNode(0), ans = l;
    var carry = 0;
    while(l1 || l2 ){
        let v1 = l1 ? l1.val : 0;
        let v2 = l2 ? l2.val : 0;
        let sum = v1 + v2 + carry;
        if(sum >= 10){
            l.val = sum - 10;
            carry = 1;
        }else{
            l.val = sum;
            carry = 0;
        }
        if(l1) l1 = l1.next;
        if(l2) l2 = l2.next;
        if(l1 || l2 || carry == 1){
            l.next = new ListNode(0);
            l = l.next;
        }
    }
    if(carry == 1) l.val = 1;
    return ans;
};

