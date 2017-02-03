#include <iostream>
#include <vector>

using namespace std;

class Point{
private:
	int row;
	int col;
public:
	Point(int row = 0, int col = 0) {
		this->row = row;
		this->col = col;
	}
	int getCol() const {
		return col;
	}
	int getRow() const {
		return row;
	}
	Point& getPoint() {
		return *this;
	}
	void setPoint(int row, int col) {
		this->row = row;
		this->col = col;
	}
	bool isEqual(const Point& point) {
		return point.getRow() == row && point.getCol() == col;
	}
};

int groundRow, groundCol;		// 전역변수

vector<Point>* checkSide(const Point& point, bool** rectangle){
	int row = point.getRow();
	int col = point.getCol();
	vector<Point>* tmpVector = new vector<Point>();
	Point tmpPoint;
	if (row != 0 && rectangle[row-1][col] == true) {
		tmpPoint.setPoint(row - 1, col);
		tmpVector->push_back(tmpPoint);
	}
	if (col != 0 && rectangle[row][col-1] == true) {
		tmpPoint.setPoint(row, col - 1);
		tmpVector->push_back(tmpPoint);
	}
	if (row != groundRow - 1 && rectangle[row+1][col] == true) {
		tmpPoint.setPoint(row + 1, col);
		tmpVector->push_back(tmpPoint);
	}
	if (col != groundCol - 1 && rectangle[row][col+1] == true) {
		tmpPoint.setPoint(row, col + 1);
		tmpVector->push_back(tmpPoint);;
	}
	return tmpVector;
}

int main()
{
	int dataCase;
	cin >> dataCase;
	int* resultArray = new int[dataCase];
	for (int i = 0; i < dataCase; i++)
	{
		int numberofCabbage;
		cin >> groundCol >> groundRow >> numberofCabbage;
		bool** rectangle = new bool*[groundRow];
		for (int i = 0; i < groundRow; i++) {
			rectangle[i] = new bool[groundCol];
			for (int j = 0; j < groundCol; j++) {
				rectangle[i][j] = false;
			}
		}
		for (int i = 0; i < numberofCabbage; i++) {
			int row, col;
			cin >> row >> col;
			rectangle[col][row] = true;
		}
		vector<Point> pointsVector;
		int count = 0;
		for (int i = 0; i < groundRow; i++) {
			for (int j = 0; j < groundCol; j++) {
				if (rectangle[i][j] == true) {
					Point tmpPoint(i, j);
					pointsVector.push_back(tmpPoint);
					while (!pointsVector.empty()) {
						Point tmpPoint = pointsVector.at(pointsVector.size()-1);
						pointsVector.pop_back();						
						rectangle[tmpPoint.getRow()][tmpPoint.getCol()] = false;
						vector<Point>* pointArray = checkSide(tmpPoint, rectangle);	
						for (int i = 0; i < pointArray->size(); i++) {
							    bool tmp= false;
								for (int j = 0; j < pointsVector.size(); j++)
									tmp += pointsVector[j].isEqual(pointArray->at(i));
								if (tmp == false)
									pointsVector.push_back(pointArray->at(i));
						}
						delete pointArray;
					}
					count++;
				}
			}
		}
		resultArray[i] = count;
	}
	for (int i = 0; i < dataCase; i++)
		cout << resultArray[i] << endl;
}
