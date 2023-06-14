<?php
$servername = "localhost";
$username = "id20891768_kelompokgacor";
$password = "Januari01#";
$dbname = "id20891768_database";


$con = mysqli_connect($servername,$username,$password,$dbname);

if(!$con){
    die("Koneksi Gagal".mysqli_connect_error());
}

$webhs = json_decode(file_get_contents('php://input'),true);
$topic = @$webhs['topic'];
$payload = @$webhs['payload'];

$sql = "INSERT INTO iotuasdata (topic,payload) VALUES ('$topic','$payload')";


mysqli_query($con,$sql);

?>