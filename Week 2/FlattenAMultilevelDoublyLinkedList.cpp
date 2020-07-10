// Time complexity :- O(n)
// Space complexity :- O(n)
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        
        if(head == NULL)   return head;
        Node* curr = head;
        Node* prev = NULL;
        stack<Node*>st;
        
        while(curr)
        {
            prev = curr;
            if(curr->child)
            {
                st.push(curr);
                curr = curr->child;
            }
            else
            {
                curr = curr->next;
            }
        }
        curr = prev;
        while(!st.empty())
        {
            Node* node = st.top();st.pop();
            //join
            curr->next = node->next;
            if(node->next)
            {
                node->next->prev = curr;
                curr = node->next;
            }
            node->next = node->child;
            node->next->prev = node;
            
            node->child = NULL;
            
            while(curr->next)
            {
                curr = curr->next;
            }
        }
        return head;
    }
};