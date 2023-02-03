
    int countRentedBooths() {
        int count = 0;
        for (Order order : orders) {
            if (order.endTime > time(NULL)) {
                count++;
            }
        }
        return count;
    }

    Booth getBoothInfo(string boothCode) {
        int index = boothMap[boothCode];
        return booths[index];
    }

    int calculateRentalCost(Order order) {
        int index = boothMap[order.boothCode];
        Booth booth = booths[index];
        if (booth.type == 0) {
            return booth.area * 100000 * (order.endTime - order.startTime);
        } else {
            return booth.area * 120000 * (order.endTime - order.startTime) + booth.numFans * 50000 * (order.endTime - order.startTime);
        }
    }

    int calculateRevenue(int startTime, int endTime) {
        int revenue = 0;
        for (Order order : orders) {
            if (order.startTime >= startTime && order.endTime <= endTime) {
                revenue += calculateRentalCost(order);
            }
        }
        return revenue;
    }

    void updateRentalCost(int newCost) {
        for (Booth& booth : booths) {
            if (booth.type == 0) {
                booth.area = newCost;
            }
        }
    }

    void updateFanCost(int newCost) {
        for (Booth& booth : booths) {
            if (booth.type == 1) {
                booth.numFans = newCost;
            }
        }
    }
};
