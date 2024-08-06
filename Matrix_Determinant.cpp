#include <iostream>
#include <vector>

using namespace std;

long long determinant(vector< vector<long long> > m) {
  if (m.size() == 1) return m[0][0];
  long long result = 0;
  for (int i = 0; i < m.size(); i++) {
    vector< vector<long long> > submatrix;
    for (int j = 1; j < m.size(); j++) {
      vector<long long> row;
      for (int k = 0; k < m.size(); k++) if (k != i) row.push_back(m[j][k]);
      submatrix.push_back(row);
    }
    result += determinant(submatrix) * (i % 2 == 0 ? m[0][i] : -m[0][i]);
  }
  return result;
}