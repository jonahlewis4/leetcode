class Foo {
public:
    atomic<bool> firstRan = false;
    atomic<bool> secondRan = false;

    Foo() {
        
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        firstRan.store(true);
        firstRan.notify_one();
    }

    void second(function<void()> printSecond) {
        
        // printSecond() outputs "second". Do not change or remove this line.
        firstRan.wait(false);
        printSecond();
        secondRan.store(true);
        secondRan.notify_one();
    }

    void third(function<void()> printThird) {
        
        // printThird() outputs "third". Do not change or remove this line.
        secondRan.wait(false);
        printThird();
    }
};