# UAS_IOT

* Anggota Kelompok
* Deskripsi Projek
* Broker Yang Digunakan
* Topik Yang Digunakan
* Alur Projek
* Tampilan Platform

# Anggota Kelompok
* Yanuar Gideon Simanlango - 2009106014
* Naufal Vigar Gani - 2009106019
* Muhammad naufal Wildan - 2009106037
* Erman Parni Simanjuntak - 2009106046

# Deskripsi Projek
Projek ini merupakan aplikasi smarthome yang berbasis internet of things dengan menggunakan platform shiftr.io sebagai metode mqtt dan platform iot yang digunakan adalah kodular. aplikasi ini dapat menampilkan kelembaban, suhu, dan menongontrol mati nyala lampu LED yang terdiri dari 4 ruangan yaitu kitchen, bathroom, bedroom, dan living room.

# Broker Yang Digunakan
* https://kelompokgacor.cloud.shiftr.io/

![image](https://github.com/NaufalWildan/UAS_IOT/assets/74341657/20fcc00a-af63-4a9e-b25e-38f156af06ec)


# Topik Yang Digunakan
### Wokwi
* uas/iot/kelembapan/bed
* uas/iot/kelembapan/bath
* uas/iot/kelembapan/living
* uas/iot/kelembapan/kitchen
* uas/iot/suhu/bed
* uas/iot/suhu/bath
* uas/iot/suhu/living
* uas/iot/suhu/kitchen
* uas/iot/led/kitchen
* uas/iot/led/living
* uas/iot/led/bath
* uas/iot/led/bed

# Alur Projek
Sensor DHT akan mempublish suhu dan kelembaban ke setiap ruangan broker yang sudah ditetapkan. Kodular, database, dan website akan menerima data yang di publish oleh DHT. Kontroling LED akan mengambil data yang dipublish kodular dikirimkan ke broker lalu LED pada wokwi akan menyala dan mati. data yang ditampilkan di website dan kodular adalah data terakhir yang dikirimkan oleh broker. 

# Tampilan Platform
* Halaman Utama
![image](https://github.com/NaufalWildan/UAS_IOT/assets/74341657/a33c1328-5280-4730-9df3-b168ab506ff2)

* Halaman Bathroom
![image](https://github.com/NaufalWildan/UAS_IOT/assets/74341657/20584660-d0e9-490b-9c2e-58bc9cd7a8b1)

* Halaman Living Room
![image](https://github.com/NaufalWildan/UAS_IOT/assets/74341657/9af99905-d048-480e-8d5b-ad4ebea9ad20)

* Halaman Kitchen
![image](https://github.com/NaufalWildan/UAS_IOT/assets/74341657/c93c26a2-13d4-4966-98d7-073676b04689)

* Halaman Bedroom
![image](https://github.com/NaufalWildan/UAS_IOT/assets/74341657/fe5f2378-d7f7-4ba5-be34-603a7b77e63b)


* Kodular



![WhatsApp Image 2023-06-14 at 15 59 40](https://github.com/NaufalWildan/UAS_IOT/assets/74341657/9bc0a09d-85f6-4181-b1ef-05f642916c5a)

