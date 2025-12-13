
class Node {
    int data;
    Node next;
    
    
    Node(int data1, Node next1){
        this.data = data1;
        this.next = next1;
    }

    
    Node(int data1){
        this.data = data1;
        this.next = null;
    }

};


public class linkedlist {
    private static Node convertArr2LL(int[] arr){
        Node head = new Node(arr[0]);
        Node mover = head;

        for(int i = 1 ; i<arr.length ; i++){
            Node temp = new Node(arr[i]);
            mover.next= temp;
            mover = temp;
        }
        return head;
    }

    private static Node removeshead(Node head){
        if(head == null) return head;
        head = head.next;
        return head;
        
    }

    private static Node removetail(Node head){
        if(head == null || head.next == null) return null;
        Node temp = head;
        while(temp.next.next != null){
            temp = temp.next;
        }  
        temp.next = null;

        return head;  
    }

    private static Node removeatK(Node head,int k){
    
        if(head == null) return head;

        if(k==1){
            Node temp = head;
            head = head.next;
            
            return head;
        }

        int count = 0; 
        Node temp = head; 
        Node previous = null;

        while (temp!= null){
            count++;
            if(count == k){
                previous.next = previous.next.next;
                break;
            }
            previous = temp;
            temp = temp.next;
        }
        return head;

    }

    public static void main(String[] args) {
        int[] arr =  {12,9,17,5};

        Node head = convertArr2LL(arr);
        System.out.println(head.data); 
        Node temp = head;
         

        while(temp!=null){
        System.out.println(temp.data);
        temp = temp.next;
        
        // head = removeshead(head);

        // head = removetail(head);
        head = removeatK(head,3);
        }
    
    }
}
