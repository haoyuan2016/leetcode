class Solution {
public:
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
	if (gas.empty() || cost.empty() || gas.size() != cost.size()) return -1;
	if(gas.size() == 1) return gas[0] >= cost[0] ? 0: -1;
	int index = 0;
	int n = gas.size();
	while (index < n)
	{
		int stepsNeeded = 0;
		int left = 0;
		while (stepsNeeded < n)
		{
			stepsNeeded++;
			if (left < 0)
			{
				index = index + stepsNeeded - 1;
				break;
			}
			else if (left + gas[index] - cost[index] < 0)
			{
				index = index + stepsNeeded;
				break;
			}
			else
				left = left + gas[(index + stepsNeeded - 1) % n] - cost[(index + stepsNeeded - 1) % n];
		}
		if (stepsNeeded == n)
		    if(left >= 0) return index;
		else
		    return -1;
	}
	return -1;
}
};
