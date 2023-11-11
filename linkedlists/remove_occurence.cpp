
class ListNode {
public:
	int data;
	ListNode* next;

	ListNode(int data) {
		this->data = data;
		this->next = NULL;
	}
};

ListNode* removeOccurences(ListNode* head, int key) {
	// add your logic here
	int test;
	cin >> test;
	int length;
	for (int t =0; t < test; t++){
	cin >> length;
	head -> next = new ListNode;
	ListNode* curr = head->next;
	for (int i = 0; i < length; i++){
		cin >> curr ->data;
		curr -> next = new ListNode;
		curr = curr -> next;
	}
	cin >> key;
	ListNode* prev = head;
	ListNode* cur = head -> next;
		
	for( int i = 0; i < length; i++ ){
		if (cur->data == key){
			prev->next = cur ->next;
			prev = cur -> next;
			cur -> next = NULL;
			delete cur;
			cur = prev->next;
			continue;				
		}
		else{
			prev = prev->next;
			cur = cur ->next;
		}		
	}
	ListNode* now = head;
	for (; now != NULL; now = now->next){
		cout << now->data;
	}
		
		
	}	
		
}
