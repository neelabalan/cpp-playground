/*
 * inheritance of interface
 * inheritance of implementation
*/

class Dog {
    public:
        virtual void bark() = 0;
        virtual void eat() { std::cout << "eating"; }
        void run() { std::cout << "running"; }
};

class YellowDog: public Dog {
    public:
        virtual void barks() { std::cout<< "yellow dog barks "; }
};

/* types of inheritance
 * 1. pure vitual public function - inherit the interface only
 * 2. non-virtual public function - inherit both the interface and implementation
 * 3. impure public virtual function - inherit the interface and default implementation
 * 4. protected function - inherit the impl only
> very important to seperate the concepts and interface and impl
*/
