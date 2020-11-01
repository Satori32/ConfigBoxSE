#include <iostream>
#include <vector>
#include <memory>
#include <string>

//remake the ConfigBox.

template<class T>
class ConfigBoxSE {
public:
//	template<class T>
	class Box {
	public:

		//Box(const std::string& In) :Name(In) {//easter egg.

		typedef T DataT;
		//	typedef Box CB;

		bool PushData(std::shared_ptr<T> In) {
			Data.push_back(In);
			return true;
		}
		bool PushBox(const Box& In) {//シェアードポインタにしてもいいね。
			Boxs.push_back(In);
			return true;
		}
		std::size_t BoxCount() {
			return Boxs.size();
		}

		std::size_t DataCount() {
			return Data.size();
		}

		std::shared_ptr<T> IndexData(std::size_t Idx) {
			return Data[Idx];
		}
		
		Box& IndexBox(std::size_t Idx) {
			return Boxs[Idx];
		}
	
		std::shared_ptr<T> operator [](std::size_t In) {
			return Data[In];
		}
		const std::shared_ptr<T> operator[](std::size_t In) const {
			return Data[In];
		}

		typename std::vector<Box>::iterator begin() {
			return Boxs.begin();
		}
		typename std::vector<Box>::const_iterator begin() const {
			return Boxs.cbegin();
		}
		typename std::vector<Box>::iterator end() {
			return Boxs.end();
		}
		typename std::vector<Box>::const_iterator end() const {
			return Boxs.cend();
		}
		//const std::string GetName() {
		//	return Name;
		//}
	protected:
		std::vector<std::shared_ptr<T>> Data;
		std::vector<Box> Boxs;
		//std::string Name="Box";
	};
public:
	bool PushData(const T& In) {
		D.push_back(std::make_shared<T>(In));
		return true;
	}
/** /
	bool PushBox(const Box& In) {
		B.PushBox(In);
		return true;
	}
/**/
/** /
	std::size_t BoxCount() {
		return B.BoxSize();
	}
/**/
	std::size_t DataCount() {
		return D.size();
	}

	std::shared_ptr<T> IndexData(std::size_t In) {
		return D[In];
	}
/**/
	Box& GetRoot() {
		return B;
	}
/**/

	std::shared_ptr<T> operator[](std::size_t In) {
		return D[In];
	}

	typename std::vector<Box>::iterator begin() {
		return B.begin();
	}
	typename std::vector<Box>::iterator end() {
		return B.end();
	}
	typename std::vector<Box>::const_iterator begin() const {
		return B.begin();
	}
	typename std::vector<Box>::const_iterator end() const{
		return B.end();
	}

protected:
	std::vector<std::shared_ptr<T>> D;
	Box B;
};

int main() {
	ConfigBoxSE<int> CB;
	ConfigBoxSE<int>::Box B;
	{
		for (std::size_t i = 0; i < 16; i++) {
			CB.PushData(i);
		}


		for (std::size_t i = 0; i < 16; i++) {
			B.PushData(CB.IndexData(i));
		}
	}
	CB.GetRoot().PushBox(B);
	CB.GetRoot().PushBox(B);
	CB.GetRoot().PushBox(B);
	CB.GetRoot().IndexBox(0).PushBox(B);

	return 0;

}