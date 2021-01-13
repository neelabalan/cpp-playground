class Dawg {
    Dawg();                          // default constructor
    Dawg( const Dawg& );              // copy constructor
    Dawg& operator=( const Dawg& );   // copy assignment operator
    ~Dawg();                         // destructor

    // c++ 11
    Dawg( Dawg && );              // move constructor
    Dawg& opearator=( Dawg && );  // move assignment operator
}
