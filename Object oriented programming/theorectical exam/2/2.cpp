#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>
using namespace std;


class Encoder {
public:
	//Encoder() {}
	virtual string encode(string msg) = 0;
	~Encoder() {}
};

class AlienEncoder : public Encoder {
private:
	string header;
public:
	AlienEncoder(string h) : header{ h } {}
	string encode(string msg) {
		string encodedMessage;
		encodedMessage = msg + header;
		return encodedMessage;
	}
};

class MorseEncoder : public Encoder {
public:
	string encode(string msg) {
		string encodedMessage = "";
		for (int i = 0; i < msg.size(); i++)
			encodedMessage += ".";
		return encodedMessage;
	}
};

class Mixer : public Encoder {
private:
	shared_ptr<Encoder> e1, e2;
public:
	Mixer(shared_ptr<Encoder> val1, shared_ptr<Encoder> val2) : e1{ val1 }, e2{ val2 } {}
	string encode(string msg) {
		string encodedMessage;
		string encoded1 = e1->encode(msg), encoded2 = e2->encode(msg);
		for (int i = 0; i < max(encoded1.size(), encoded2.size()); i++)
		{
			if (i % 2 == 0)
			{
				if(i < encoded2.size())
					encodedMessage += encoded2[i];
			}
				
			else
			{
				if (i < encoded1.size())
					encodedMessage += encoded1[i];
			}
				
		}
		return encodedMessage;
	}
};

class Communication { // concatenate strings
private:
	vector<string> messages;
	shared_ptr<Encoder> encoder;
public:
	Communication(shared_ptr<Encoder> enc) : encoder{ enc } {}
	void addMessage(string msg)
	{
		messages.push_back(msg);
		sort(messages.begin(), messages.end());
	}
	string communicate()
	{
		string finalString = "";
		string encodedMessage;
		for (auto s : messages)
		{
			encodedMessage = encoder->encode(s);
			finalString += encodedMessage + " ";
		}
		return finalString;
	}
};


int main()
{
	MorseEncoder morse;
	AlienEncoder alien("ET");
	Mixer mixer(make_shared<AlienEncoder>(alien), make_shared<MorseEncoder>(morse));
	Communication comm1(make_shared<MorseEncoder>(morse)), comm2(make_shared<Mixer>(mixer));
	comm1.addMessage("hello");
	comm2.addMessage("hello");
	comm1.addMessage("goodbye");
	comm2.addMessage("goodbye");
	cout << comm1.communicate() << '\n' << comm2.communicate();
	return 0;
}