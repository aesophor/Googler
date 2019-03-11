import java.util.List;
import java.util.ArrayList;

interface A<T> {

    void f(T t);

}


class C<T> implements A<T> {  // Raw type is usually a sign of poor quality code.

    public void f(T t) {
        ;
    }

    // Generic method. The class itself does NOT have to be generic.
    public <E> void genericMethod(E e) {
        System.out.println(e.toString());
    }
}


public class Generics {

    public static void main(String[] args) {
        C<String> c = new C<>();
        // C<?> unknown = new C<?>(); // Compilation error.
        C<?> unknown = new C<String>();
        
        List<String> l = new ArrayList<>();
        l.add("hello");
        l.add("world");
        System.out.println(l);
    }

}
