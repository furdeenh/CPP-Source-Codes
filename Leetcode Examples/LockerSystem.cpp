#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>    // rand(), srand()
#include <ctime>      // time()
#include <stdexcept>  // invalid_argument, runtime_error

using namespace std;

class Package {
public:
    string id;
    string code;
    string status;
    int lockerIndex;
    int expiryDay;
    bool openedByStaff;

    Package(string packageId, string packageCode, int index, int day)
        : id(packageId),
          code(packageCode),
          status("delivered"),
          lockerIndex(index),
          expiryDay(day + 7),
          openedByStaff(false) {}
    
    bool isExpired(int currentDay)
    {
        return currentDay >= expiryDay;
    }
};

class Locker {
public:
    int id;
    string size;
    bool available;

    Locker(int lockerId, string lockerSize): id(lockerId), size(lockerSize), available(true) {}

    void open()
    {
        cout << "Opening Locker " << id << endl;
    }
};

class LockerSystem {
private:
    vector<Locker> lockers;
    vector<Package> packages;

    int findPackage(string code)
    {
        for (size_t i = 0; i < packages.size(); ++i)
        {
            if (packages[i].code == code)
            {
                return i;
            }
        }
        return -1;
    }

    string generateCode()
    {
        string code;
        do {
            code = to_string(100000 + rand() % 900000);
        } while (findPackage(code) != -1);
        return code;
    }

public:
    LockerSystem()
    {
        for (int i = 1; i <= 10; ++i) {
            lockers.push_back(Locker(i, "small"));
            lockers.push_back(Locker(i + 10, "medium"));
            lockers.push_back(Locker(i + 20, "large"));
        }
    }

    string deliver(string packageId, string size, int currentDay)
    {
        if (size != "small" && size != "medium" && size != "large")
        {
            throw invalid_argument("Invalid package size.");
        }

        for (const Package& package: packages)
        {
            if (package.id == packageId && package.status == "delivered")
            {
                throw runtime_error("Package is already delivered.");
            }
        }
        
        for (int i = 0; i < lockers.size(); ++i)
        {
            Locker& locker = lockers[i];
            if (locker.size == size && locker.available)
            {
                string code = generateCode();
                packages.push_back(Package(packageId, code, i, currentDay));
                
                // Fixed: Moved these inside the if-block so only the assigned locker changes state
                locker.available = false;
                locker.open();
                return code;
            }
        }
        throw runtime_error("No available locker of that size");
    }

    void pickup(string code, int currentDay)
    {
        int index = findPackage(code);

        if (index == -1) {
            throw invalid_argument("Invalid package code.");
        }

        Package& package = packages[index];

        if (package.status == "picked-up") {
            throw runtime_error("Package code already used.");
        }

        if (package.status == "returned") {
            throw runtime_error("Package was removed by staff.");
        }

        if (package.isExpired(currentDay)) {
            throw runtime_error("Package code expired.");
        }

        Locker& locker = lockers[package.lockerIndex];
        locker.open(); // Fixed: Added missing parentheses ()
        package.status = "picked-up";
        locker.available = true;

        cout << "Picked up package " << package.id << endl;
    }
    
    void openExpiredLockers(int currentDay)
    {
        for (Package& package : packages)
        {
            if (package.status == "delivered" && package.isExpired(currentDay))
            {
                Locker& locker = lockers[package.lockerIndex]; // Fixed: Changed 'locker' to 'lockers' vector name
                locker.open();
                package.openedByStaff = true;
            }
        }
    }

    void confirmStaffRemoval(string code) {
        int index = findPackage(code);

        if (index == -1) {
            throw invalid_argument("Invalid package code.");
        }

        Package& package = packages[index];

        if (package.status != "delivered") {
            throw runtime_error("Package is no longer in a locker.");
        }

        if (!package.openedByStaff) {
            throw runtime_error("Staff must open the locker first.");
        }

        Locker& locker = lockers[package.lockerIndex];
        package.status = "returned";
        locker.available = true;

        cout << "Staff removed package " << package.id << endl;
    }
};

int main(){
    srand(time(nullptr));

    LockerSystem system;

    try{
        string code1 = system.deliver("Toy", "medium", 1);
        string code2 = system.deliver("Phone", "small", 1);

        cout << "Toy code: " << code1 << endl;
        cout << "Phone code: " << code2 << endl;

        system.pickup(code1, 3); // Fixed: Changed pickUp to pickup (lowercase u)

        // PKG2 remains inside on day 8. Its code is expired.
        try {
            system.pickup(code2, 8); // Fixed: Changed pickUp to pickup
        }
        catch (const exception& error) {
            cout << error.what() << endl;
        }

        // Staff opens expired lockers and confirms PKG2's removal.
        system.openExpiredLockers(8);
        system.confirmStaffRemoval(code2);
    }
    catch (const exception& error) {
        cout << error.what() << endl;
    }

    return 0;
}