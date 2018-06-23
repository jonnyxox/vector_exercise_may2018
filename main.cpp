
#include <cassert>
#include <iostream>
#include <vector>
//#include <assert.h>

void printVec(const std::vector<int> &test) {
    for (int i=0; i<test.size(); ++i) {
        std::cout << test[i] << ", "<< test.size() <<"\n";
    }
    std::cout <<"\n";
}

int main() {
    // 1. Create a vector of ints containing elements 1, 2, 3
    std::vector<int> test{1, 2, 3};

    // 2. Use assert() to check that the vector contains three elements
    assert (test.size() == 3);
    std::cout << "not three elements\n";
    // 3. Add two more elements to the back of the array
    //    What is its new capacity?
//test.push_back(5);
//test.push_back(5); // or
    int myAdd[]{6, 7};
    test.insert(test.end(), myAdd, myAdd + 2);

    printVec(test);
    // 4. Remove the last element from the array
    //    What is its size?
    //    What is its capacity?
    test.pop_back();
    printVec(test);

    // 5. Use a range-for loop to set every element of the vector to 42
    int count{0};
    for (int i : test) {
        test[count] = 42;
        ++count;
    }
    printVec(test);

    // 6. Set the second element of the vector to 99
    //    Hint: remember C++ indexes arrays from zero!

    test[1] = 99;
    printVec(test);
    // 7. Use a range-for loop to print every element of the function
    //    For bonus points: make this a separate function called print_vec()
    count = 0;
    for (int i : test) {
        std::cout << test[count] << "\n";
        ++count;
    }

    // 8. Use a single member function to remove all elements from the vector
    //    Use assert() to check that this has worked correctly
    test.clear();
    assert (test.size() == 0);
    std::cout << "Vector cleared\n";
    assert (test.empty());
    std::cout << "Vector cleared\n";
    // 9. What is the capacity of your vector now?
    //    Use a member function to reset the capacity to zero

    std::cout << "test.size() = " << test.size() << "\n";

    // 10. Try reading the 99th element of the vector. What happens?
    std::cout << "test[98] = " << test[98] << "\n"; // returns0

    //     Now, try using the at(idx) member function to read the 99th element.
    //     What happens this time?
    try {
        std::cout << "test.at(98) = " << test.at(98) << "\n";
        std::cout << "test.khgkgbat(98)" << "\n";
    }
    catch (const std::out_of_range &e) {
        std::cerr << "Oops! Range error\n";
        // error generated when reading
        // assert (test.at(98)); std::cout << "test.at(98) = no go" << "\n";
    }
    catch (... ) {
        std::cerr <<"Error\n";
        // error generated when reading
        // assert (test.at(98)); std::cout << "test.at(98) = no go" << "\n";
    }
}
