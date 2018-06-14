// Description: An incomplete implementation of iterators for a
//              RingQueue class.
//
// Notes: The project DOES compile but there is no meaningful 
//              output
//
// Your job: To complete this set of classes so that the output
//              produced by 'main' (below), matches the sample
//              file provided at the end of this file.


#include <iostream>

// Forward declaration
template <typename ItemType, int MAX_SIZE>
class RingQueue;



template <typename ItemType, int MAX_SIZE>
class RingQueue{
    
    // Nested Forward declaration of RingQueue<ItemType,MAX_SIZE>::iterator
    // This is needed if one plans to turn this home-made iterator into
    // one of the special categories of iterators (e.g., input, output,
    // forward, etc.).
    public: 
        class iterator;



    // Aliases. 
    typedef ItemType* pointer;
    typedef ItemType& reference;



    // Definition of RingQueue<ItemType,MAX_SIZE>::iterator
    public:
        class iterator{
            private:
                // A link to the parent container 
                RingQueue* parent;

                // The position within the RingQueue is determined
                // by how far ahead we are from the begining of the
                // queue.
                int offset;

            private:  // Private constructor???
                iterator(RingQueue* _parent, int _offset = 0 )
                  : parent(_parent), offset(_offset) { }

                
            // It is quite common for Containers and their iterators
            // to be friends. After all, they should work closely together.
            friend class RingQueue<ItemType,MAX_SIZE>;


            public:
                reference operator*() {
                    // Replace the line(s) below with your code.
                    return parent->buffer[0] ;  
                }

                iterator& operator++(){
                    // Replace the line(s) below with your code.
                    return *this;
                }

                iterator operator++( int unused ){
                    // Replace the line(s) below with your code.
                    return *this;
                }

                bool operator==( const iterator& rhs ) const {
                    // Replace the line(s) below with your code.
                    return true;
                }

                bool operator!=( const iterator& rhs ) const {
                    // Replace the line(s) below with your code.
                    return true;
                }

        };



        /**
        class const_iterator{
            private:
                RingQueue* parent;
                int offset;

            private:
                // Only RingQueue objects can create const_iterators...
                const_iterator() ;

            public:
                // ... however, const_iterators can be 'copied'.
                const_iterator( const const_iterator& ) ;

            friend class RingQueue<ItemType,MAX_SIZE>;
        };
        */



    // Friendship goes both ways here.
    friend class iterator;
    // friend class const_iterator;  // not implemented... yet.



    private:
        // A fixed-size static array with constant capacity that represents 
        // the RingQueue
        ItemType buffer[MAX_SIZE];

        // The starting index. It changes according to a very 
        // specific set of rules (below).
        int begin_index;

        // The actual size of the RingQueue. Not to be confused with
        // its capacity. 
        int ring_size;



        // A helper function that computes the index of 'the end'
        // of the RingQueue
        int end_index() const {
            // Replace the line(s) below with your code.
            return begin_index;
        }



    public: 
        // Constructor
        RingQueue() : begin_index(0), ring_size(0) { }

        // Accessors. Note: 'back()' is not considered part of the array.
        ItemType front() const { 
            if ( ring_size == 0 ) std::cerr<< "Warning: Empty ring!\n" ;
            // ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
            // Feel free to throw instead...
            
            
            // Replace the line(s) below with your code.
            return buffer[0];
        }
        ItemType back() const {  
            if ( ring_size == 0 ) std::cerr<< "Warning: Empty ring!\n" ;
            // ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
            // Feel free to throw instead...
            
            
            // Replace the line(s) below with your code.
            return buffer[0]; 
        }



        // Mutators
        void push_back( const ItemType& value ){
            return;
        }
        void pop_front(){
            return;
        }

        // Functions that return iterators
        iterator begin() { 
            // Replace the line(s) below with your code.
            return iterator(this,0); 
        }
        iterator end() {
            // Replace the line(s) below with your code.
            return iterator(this,0);
        }

        // Miscellaneous functions
        size_t size() const {
            // Replace the line(s) below with your code.
            return 0;
        }

        // Debugging functions
        void dump_queue() const {
            std::cout << "Raw queue...\n";
            for ( size_t i = 0 ; i < MAX_SIZE ; ++i )
                std::cout << "Val: " << buffer[i] << ", at: " << buffer+i << '\n';
            std::cout << '\n';
            return;
        }

};

int main(){
    RingQueue<int,7> rq;
    rq.dump_queue();

    for ( int i = 0 ; i < 8 ; ++i )
        rq.push_back(i+1);

    rq.dump_queue();
    rq.pop_front();

    std::cout << "Queue via size: \n";

    // RingQueue<int,7>::iterator it = rq.begin() ; 
    auto it = rq.begin() ; 
    for ( size_t i = 0 ; i < rq.size() ; ++i ) {
        std::cout << "Value: " << *it << ", address: " << &(*it) << '\n';
        ++it;
    }
    std::cout << '\n';

    

    // Uncomment the block below only when you have a working 
    // implementation of RingQueue<ItemType,int>::end(). 
    // If the implementation is not correct, it might result in 
    // an infinite loop.
    /** 
    std::cout << "Queue via iterators: \n";
    for ( auto it = rq.begin() ; it != rq.end() ; ++it ) {
        std::cout << "Value: " << *it << ", address: " << &(*it) << '\n';
    }
    std::cout << '\n';
    */



    rq.dump_queue();

    return 0;
}



