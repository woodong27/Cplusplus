void init(int L, int M) {
	//L : 생산 라인의 갯수, M : 장비의 갯수
	return;
}

int request(int tStamp, int pId, int mLine, int eId, int mTime) {
	// tStamp 시각에 pld제품의 생산요쳥이 mLine에 들어옴
	// eld : 필요한 장비, mTime : 생산에 걸리는 시간
	// tStamp시각에 생산을 시작하면 생산을 시작한 제품의 ID를 반환
	// tStamp시각에 생산이 완료되고 대기중인 요청이 없거나 장비를 대기해야 하면 -1반환
	return 0;
}

int status(int tStamp, int pId) {
	//tStamp시각에 pld제품의 상태를 확인
	//생산요청이 없었으면 0, 라인에서 대기중이면 1, 생산중이면2, 완료되었으면 3반환
	return 0;
}
