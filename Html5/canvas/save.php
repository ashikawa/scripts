<?php
$data = $_POST['data'];

// メタ情報 (コンテンツタイプ) を削除
$data = preg_replace("/^.*?,/", "", $data);

file_put_contents("./test.png", base64_decode($data));

header("Content-Type: application/json; charset=UTF-8");
echo json_encode(array("src" => "/Html5/canvas/test.png"));
