$(function() {
	// Workerのインスタンスを生成する
	var worker = new Worker('/Html5/js/worker/worker1.js');
	// イベントリスナー
	function onMessage(e) {
		// イベントデータのログ書きだし
		console.log(e.data);
	}
	// messageイベントのリスナーを追加
	worker.addEventListener('message', onMessage, false);
	
	
	
	function onError(e){
		console.log(e);
	}
	worker.addEventListener("error", onError , true);
	
	// オブジェクトを送信
	worker.postMessage({ x : 100, y : 200 });
});
