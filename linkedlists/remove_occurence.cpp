/* This is the ListNode class definition

class ListNode {
public:
	int data;
	ListNode* next;

	ListNode(int data) {
		this->data = data;
		this->next = NULL;
	}
};
*/
ListNode* removeOccurences(ListNode* head, int key) {
	// add your logic here
	int length;
	cin >> length;
	head ->next = new ListNode;
	ListNode* curr = head->next;
	for (int i = 0; i < length; i++){
		cin >> curr ->item;
		curr -> next = new ListNode;
		curr = curr -> next;
	}
	cin >> key;
	ListNode* current = head;
	ListNode* forward = head -> next;
	//if ( head -> item == key){
	//	head = head -> next;
	//	ListNode* current = head 
	//}
		
		
	for ( int i = 0; i < length; i++){
		if ( key == current -> item){
			prev -> next = current -> next;
			current = current -> next;
		
			
		}
		
		
		
		
		
	}
		
		
		
		
}
