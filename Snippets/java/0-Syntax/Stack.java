class Node<T> {

    private T _data;
    private Node<T> _next;

    public Node(T data) {
        _data = data;
        _next = null;
    }

    public T getData() {
        return _data;
    }

    public Node<T> getNext() {
        return _next;
    }

    public void setNext(Node<T> next) {
        _next = next;
    }

}


public class Stack<T> {
    
    private Node<T> _top;

    public Stack() {
        _top = null;
    }
    
    public void push(T data) {
        if (isEmpty()) {
            _top = new Node<T>(data);
        } else {
            Node<T> ptr = new Node<T>(data);
            ptr.setNext(_top);
            _top = ptr;
        }
    }

    public T pop() {
        if (isEmpty()) {
            return null;
        } else {
            Node<T> ptr = _top;
            _top = _top.getNext();
            return ptr.getData();
        }
    }

    public boolean isEmpty() {
        return (_top == null);
    }

    @Override
    public String toString() {
        String ret = "[";
        Node<T> ptr = _top;
        while (ptr != null) {
            ret = ptr.getData().toString();
        }
        return ret + "]";
    }


    public static void main(String[] args) {
        Stack<String> s = new Stack<>();
        s.push("world");
        s.push("hello");
        System.out.println(s.pop());
        System.out.println(s.pop());
    }
}
