<?php
    require('data.php');
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>IOT UAS Kelompok Gacor</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/css/bootstrap.min.css" rel="stylesheet"
        integrity="sha384-1BmE4kWBq78iYhFldvKuhfTAU6auU8tT94WrHftjDbrCEXSU1oBoqyl2QvZ6jIW3" crossorigin="anonymous">
    <link rel="stylesheet" href="style.css">
    <link rel="stylesheet" href="https://cdn.datatables.net/1.13.4/css/jquery.dataTables.min.css">
    <script src="https://code.jquery.com/jquery-3.5.1.js"></script>
    <script src="https://cdn.datatables.net/1.13.4/js/jquery.dataTables.min.js"></script>

</head>
<body>
    <div class="container-samping">
        <a href="index.php">
            <div class="logo" style="font-weight: bold; font-size: 30px;">
            <img style="width: 50px;" src="https://cdn-icons-png.flaticon.com/128/9630/9630732.png" alt="">
            Connected
        </div>
        </a>
       <a href="bath.php">
            <div class="sidebar">
            <img style="width: 30px;" src="https://cdn-icons-png.flaticon.com/128/1837/1837443.png" alt="">
            Bathroom
        </div>
       </a>
       <a href="living.php">
            <div class="sidebar">
            <img style="width: 30px;" src="https://cdn-icons-png.flaticon.com/128/963/963843.png" alt="">
            Livingroom
        </div>
       </a>
       <a href="kitchen.php">
            <div class="sidebar">
            <img style="width: 30px;" src="https://cdn-icons-png.flaticon.com/128/2082/2082000.png" alt="">
            Kitchen
        </div>
       </a>
        <a href= "bed.php">
            <div class="sidebar" >
            <img style="width: 30px;" src="https://cdn-icons-png.flaticon.com/128/3030/3030335.png" alt="">
            Bedroom
        </div>
        </a>
    </div>
    <div class="content">
        <table id="example" class="display" style="width:100%">
            <thead>
                <tr>
                    <td>No</td>
                    <td>Topic</td>
                    <td>Payload</td>
                    <td>Time</td>                
                </tr>
            </thead>
            <?php
            include "data.php";
            $no = 1;
            $query = mysqli_query($con, 'SELECT * FROM `iotuasdata` WHERE `topic` = "uas/iot/suhu/bath" OR `topic`= "uas/iot/kelembapan/bath";');
            while ($data = mysqli_fetch_array($query)) {
            ?>
                <tr>
                    <td><?php echo $no++ ?></td>
                    <td><?php echo $data['topic'] ?></td>
                    <td><?php echo $data['payload'] ?></td>
                    <td><?php echo $data['time'] ?></td>
                </tr>
            <?php } ?>
        
    </div>
    <script>
        $(document).ready(function () {
            $('#example').DataTable();
        });
    </script>



</body>

</html>