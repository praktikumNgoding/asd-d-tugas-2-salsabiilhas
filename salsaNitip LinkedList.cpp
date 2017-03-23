#include <iostream>
#include <string>
using namespace std;

struct data {
	string nama;
	int umur;
	data *next;
};

struct linkedTunggal {
	data *first;
};
data *alokasi_memori(string nama, int umur); //allocation list in memori
void createBox(linkedTunggal *link); //create list
void addAwal(linkedTunggal *link, data *elm); //insert list in memori
void displayList(linkedTunggal link); //View list in memori
void delloc(data *daftar); //delete list in memori
void addAkhir(linkedTunggal *list, data *elm); //insert list in last (index last)
void dellAkhir(linkedTunggal *list); //delete last insert
void update(data *yang_akan_dirubah, string nama, int umur);

//2 pembuatan gerbong dan pengisian nilai
void createBox(linkedTunggal *link) {
	link->first = NULL;
}
data *alokasi_memori(string nama, int umur) {
	data *p = new data;

	p->nama = nama;
	p->umur = umur;
	p->next = NULL;

	return p;
}

void addAwal(linkedTunggal *link, data *elm) {
	elm->next = link->first;
	link->first = elm;

	elm = NULL;
}

void displayList(linkedTunggal link) {
	if (link.first != 0) {
		data *p = link.first;
		while (p != 0) {
			cout << p->nama << p->umur << "\n";
			p = p->next;
		}
	}
	else {
		cout << "Pengisian data" << endl;
	}
}

void delloc(data *daftar) {
	delete(daftar);
}

void addAkhir(linkedTunggal *list, data *elm) {
	if (list->first != 0) {
		data *p = list->first;
		while (p->next != 0) {
			p = p->next;
		}
		p->next = elm;
		elm = 0;
	}
	else {
		addAwal(list, elm);
	}
}

void dellAkhir(linkedTunggal *list) {
	if (list->first != 0) {
		data *temp_1 = list->first;

		if (temp_1->next == 0) {
			delloc(temp_1);
		}
		else {
			data *temp_2 = temp_1;
			temp_1 = temp_2->next;
			while (temp_1->next != 0) {
				temp_2 = temp_1;
				temp_1 = temp_2->next;
			}
			temp_2->next = 0;
			delloc(temp_1);
		}
	}
	else {
		cout << "Kosong" << endl;
	}
}

void update(data *yang_akan_dirubah, string nama, int umur) {
	yang_akan_dirubah->nama = nama;
	yang_akan_dirubah->umur = umur;
}

int main()
{
	linkedTunggal link;
	createBox(&link);

	data *p1 = new data;

	p1 = alokasi_memori("SALSA, umur = ", 20);
	addAwal(&link, p1);

	p1 = alokasi_memori("ANI, umur = ", 21);
	addAwal(&link, p1);

	p1 = alokasi_memori("BELLA, umur = ", 20);
	addAwal(&link, p1);

	displayList(link);

	cout << "\n\nbelakang di hapus maka jadi :" << endl;

	//proses penghapusan gerbong list

	dellAkhir(&link);
	displayList(link);
	cout << "\n\n" << endl;
    return 0;
}

