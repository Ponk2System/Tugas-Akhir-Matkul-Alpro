#include <iostream>
#include <string>
using namespace std;

#define MAX_QUEUE_SIZE 5

class PrintSpooler {
private:
    string queue[MAX_QUEUE_SIZE];
    int front, rear, count;

public:
    PrintSpooler(){
        front = 0;
        rear = -1;
        count = 0;
    }

    void tambahDokumen(string namaDokumen){
        if (namaDokumen.empty()){
            cout << "!!! Nama dokumen tidak boleh kosong. Silakan coba lagi." << endl;
            return;
        }

        if (count == MAX_QUEUE_SIZE){
            cout << "Antrian penuh. Tidak dapat menambahkan dokumen. Tunggu printer selesai mencetak." << endl;
        } 
        else{
            rear = (rear + 1) % MAX_QUEUE_SIZE;
            queue[rear] = namaDokumen;
            count++;
            cout << ">> Dokumen '" << namaDokumen << "' berhasil ditambahkan ke antrian." << endl;
        }
    }

    void cetakDokumen(){
        if (count == 0){
            cout << "!!! Antrean kosong. Tidak ada dokumen untuk dicetak." << endl;
        } 
        else{
            cout << ">> Mencetak dokumen: '" << queue[front] << "'...Selesai!" << endl;
            front = (front + 1) % MAX_QUEUE_SIZE;
            count--;
        }
    }

    void lihatAntrean(){
        if (count == 0){
            cout << "!!! Antrean kosong. Tidak ada dokumen dalam antrian." << endl;
        } 
        else{
            cout << "\n--- Daftar Antrean Printer ---" << endl;
            int temp = front;
            for (int i=0; i<count; i++){
                cout << i + 1 << ". " << queue[temp] << endl;
                temp = (temp + 1) % MAX_QUEUE_SIZE;
            }
            cout << "-----------------------------\n" << endl;
        }
    }
};

void inputPilihan(int &pilihan){;
    //do{
        cout << "Pilih opsi (1-4): ";
        cin >> pilihan;
        
        if (cin.fail() || pilihan < 1 || pilihan > 4) {
            cin.clear();  // Clear error flag
            cin.ignore(10000, '\n');  // Clear buffer
            //cout << "!!! Pilihan tidak valid! Silakan pilih antara 1-4." << endl;
            //pilihan = 0;  // Reset pilihan
            // Retry...
        }
    //} while (pilihan < 1 || pilihan > 4);
    
}

int main(){
    PrintSpooler spooler;
    int pilihan;
    string doc;

    do{
        cout << "\n=== CLI PRINT SPOOLER ===" << endl;
        cout << "1. Tambah Dokumen ke Antrian" << endl;
        cout << "2. Cetak Dokumen" << endl;
        cout << "3. Lihat Antrean" << endl;
        cout << "4. Keluar" << endl;
        inputPilihan(pilihan);

        switch (pilihan){
            case 1:
                cout << "Masukkan nama dokumen: ";
                cin.ignore(); //untuk mengabaikan space
                getline(cin, doc);
                spooler.tambahDokumen(doc);
                break;
            case 2:
                spooler.cetakDokumen();
                break;
            case 3:
                spooler.lihatAntrean();
                break;
            case 4:
                cout << "Keluar dari program... Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid! Silakan pilih antara 1-4." << endl;
        }
    } while (pilihan != 4);

    return 0;
}