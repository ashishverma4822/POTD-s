class Solution {
  public:
    double maxVolume(double perimeter, double area) {
        double l = (double)(perimeter - sqrt(perimeter*perimeter - 24*area))/12;              
        double h = perimeter/4 - 2*l;
        double volume = l*l*h;
        return volume;
    }
};
