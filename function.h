#ifndef FUNCTION_H
#define FUNCTION_H

Word timTu(HashTable DIC, string word);             // Tim tu vung
void khoiTaoTu(Word &w,string dong);                // Ham khoi tao tu vung
void suaTu(HashTable &tudien,Word &w);              // Sua tu vung
void themTuMoi(HashTable &tudien);                  // Nhap tu vung
void timTuGoiY(HashTable &tudien, string input);    // Tim tu goi y

Word timTu(HashTable DIC, string word){
	return  DIC.Find(word);
}

void khoiTaoTu(Word &w,string dong) {  // dong doc tu file
	int i, pos;
	i = 0;
	// about/pho tu/khoang chung;sap;gan;/He is about to die;We're about to start;How about this?;
	// tach tu
	string word = "";
	while (dong[i] != '/') {word += dong[i++];}
	i++;
	w.setWord(word); // init word in class Word
	
	// tach loai tu
	string type = "";
	while (dong[i] != '/') {type += dong[i++];}
	i++;
	w.setType(type);
	
	// tach nghia
	string mean = ""; pos = 0;
	while (dong[i] != '/') {
		mean += dong[i];
		i++; 
		// nghia moi
		if (dong[i] == ';') { 
			w.setMean(mean);
		}
	}
	i++;
	
	// tach vi du
	string example = "";
	while (dong[i] != '/') {
		example += dong[i++];
		if (dong[i] == ';') {
			w.setExample(example);
		//	cout<<w.getExample();
		}
	}	
}

void suaTu(HashTable &tudien,Word &w) {
	xoaManHinh();
	
	cout << "Sua tu: '" << w.getWord()<< "':" << endl;
	// Sua loai tu
	string temp = "";
	cout << "Sua loai tu (" << w.getType() << "): ";
	getline(cin, temp);

	if (temp == "") return;
	w.setType(temp);

	// Sua nghia
	temp = "";
	cout << "Sua nghia " <<  " (" << w.getMean() << "): ";
	getline(cin, temp);
	w.setMean(temp);

	// Sua vi du
	temp = "";
	cout << "Sua vidu " <<  " (" << w.getExample() << "): ";
	getline(cin, temp);
	w.setExample(temp);
	tudien.update(w);
}


void themTuMoi(HashTable &tudien) {
	xoaManHinh();
	Word w;
	string temp = "";
	// nhap tu
	cout << "Nhap tu: ";
	getline(cin, temp);
	if (temp == "") return;
	else {
		w.setWord(temp);
	//	cout<<temp;
	}
	// nhap loai tu
	temp = "";
	cout << "Nhap loai tu: ";
	getline(cin, temp);
	w.setType(temp);
	// nhap nghia
	temp = "";
	cout << "Nhap nghia "  << ": ";
	getline(cin, temp);
	w.setMean(temp);
	
	// nhap vi du
	temp = "";
	cout << "Nhap vi du " <<  ": ";
	getline(cin, temp);
	w.setExample(temp);
    tudien.Insert(w);
}

void timTuGoiY(HashTable &tudien,Word *a, string input, int pos, int &size){

	 // Hien thi toi da 10 goi y
	size = 10;
	tudien.findByInput(a,input);
	for(int i = 0;i<10;i++){
		if(a[i].getWord() !=""){
			cout<<" "<<a[i].getWord()<<endl;
		}
		else{
			size = i;
			break;
		}
	}
	
/*		string w = tudien.findByInput(i,input);
		if(w!="")	cout<<" "<<w<<endl;
		
	if(limit<10 && w !="") {
			cout<<" "<<w<<endl;
			limit++;
		} */
	//} 
}

#endif
