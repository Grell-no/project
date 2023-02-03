#include <iostream>
#include<stdio.h>
#include <string>
#include <vector>

using namespace std;

struct Booth {
  string code;
  int area;
  string location;
};

struct HighEndBooth : public Booth {
  int coolingFans;
  int tables;
  int chairs;
};

struct StandardBooth : public Booth {
  string roofMaterial;
  string partitionMaterial;
};

struct TenantOrder {
  string name;
  string address;
  string rentalStart;
  string rentalEnd;
  string boothNumber;
  int deposit;
};

class BoothRentalManagementSystem {
 public:
  BoothRentalManagementSystem() {}

  void AddBooth(Booth booth) {
    booths_.push_back(booth);
  }

 void EditBooth(string code, Booth booth) {
  if (booths_.empty()) {
    // throw an exception or return an error
  }
  bool found = false;
  for (auto &b : booths_) {
    if (b.code == code) {
      b = booth;
      found = true;
      break;
    }
  }
  if (!found) {
    // throw an exception or return an error
  }
}
void DeleteBooth(string code) {
  if (booths_.empty()) {
    // throw an exception or return an error
  }
  bool found = false;
  for (auto it = booths_.begin(); it != booths_.end(); ++it) {
    if (it->code == code) {
      booths_.erase(it);
      found = true;
      break;
    } 
  }
  if (!found) {
    // throw an exception or return an error
  }
}
 

  vector<Booth> GetBooths() {
    return booths_;
  }

  void AddTenantOrder(TenantOrder order) {
    tenantOrders_.push_back(order);
  }

  vector<TenantOrder> GetTenantOrders() {
    return tenantOrders_;
  }

 private:
  vector<Booth> booths_;
  vector<TenantOrder> tenantOrders_;
};

int main() 
{
  BoothRentalManagementSystem system;

  Booth booth1;
  booth1.code = "B1";
  booth1.area = 100;
  booth1.location = "Hall 1";

  system.AddBooth(booth1);

  HighEndBooth highEndBooth1;
  highEndBooth1.code = "B2";
  highEndBooth1.area = 200;
  highEndBooth1.location = "Hall 2";
  highEndBooth1.coolingFans = 2;
  highEndBooth1.tables = 1;
  highEndBooth1.chairs = 4;

  system.AddBooth(highEndBooth1);

  StandardBooth standardBooth1;
  standardBooth1.code = "B3";
  standardBooth1.area = 150;
  standardBooth1.location = "Hall 3";
  standardBooth1.roofMaterial = "Metal";
  standardBooth1.partitionMaterial = "Wood";

  system.AddBooth(standardBooth1);

  auto booths = system.GetBooths();
  cout << "Booths:" << endl;
  for (const auto &b : booths) {
    cout << "Code: " << b.code << ", Area: " << b.area << ", Location: " << b.location << endl;
}
}

