/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode[]} lists
 * @return {ListNode}
 */
var mergeKLists = function(lists) {
    'use strict';
    var merge2List = (l1,l2)=>{
        if(l1 === null) return l2;
        if(l2 === null) return l1;
        var dummy = new ListNode(0), cur = dummy;
        while(l1 !== null && l2 !== null){
            if(l1.val < l2.val){
                cur.next = l1;
                l1 = l1.next;
            }else{
                cur.next = l2;
                l2 = l2.next;
            }
            cur = cur.next;
        }
        cur.next =  l1 === null ? l2 : l1;
        var t = dummy.next;
        dummy = null;
        return t;
    };
    var merge = (listArr)=>{
        var n = listArr.length;
        if(n == 0) return null;
        if(n == 1) return listArr[0];
        var ans = [];
        for(let i = 1; i < n; i += 2)
            ans.push(merge2List(listArr[i-1],listArr[i]));
        if(n % 2 !== 0) ans.push(listArr[n-1]);
        listArr = null;
        return merge(ans);
    }
    return merge(lists);
};
