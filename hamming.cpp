class Solution {
public:
	int hammingDistance(int x, int y) {
		int i;
		int temp;
		int distance = 0;
		for (i = 0; i < 32; i++) {
			temp = ((x >> i) & 0x1) - ((y >> i) & 0x1);
			if (temp < 0) {
				temp = -temp;
			}
			distance += temp;
		}
		return distance;
	}
};
