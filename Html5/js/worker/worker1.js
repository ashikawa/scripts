
// DedicatedWorkerContext
( function(worker){
	
	for (var _k in worker) {
		worker.postMessage(_k + ":" + typeof( worker[_k] ) );
	}
	
	function onMessage(e){
		// データ取りだし
		var msg = e.data;
		// 受けとったデータをメッセージ送信
		worker.postMessage('recive : [' + JSON.stringify(msg) + ':' + typeof(msg) + ']');
	};
	
	//messageイベントのリスナー追加
	worker.addEventListener('message', onMessage, false);
} )(this);
