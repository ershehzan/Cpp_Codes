#include <iostream> 
using namespace std;  
int main() {
    // This statement prints "Hello World!" to the console
    if (cout << "Hello World!" << endl) {
        // The if condition here is redundant as cout always returns a valid stream
    }

    // Corrected switch statement with proper syntax
    switch (cout << "C++ !" << endl, 0) {  
        // The comma operator evaluates 'cout << "C++ !"' first, then uses '0' in switch
        // Since 'switch' has no cases, it does nothing
    }

}
