#pragma once

// ������ʼ��
BOOL InitNetSDK();


// �����ص�����
void CALLBACK DisConnectFunc(LLONG lLoginID, char *pchDVRIP, LONG nDVRPort, LDWORD dwUser);

void CALLBACK HaveReconnFunc(LLONG lLoginID, char *pchDVRIP, LONG nDVRPort, LDWORD dwUser);

