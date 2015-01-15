
#ifndef _DLL_AACENC_H_
#define _DLL_AACENC_H_


#if defined(_WIN32) && !defined(__MINGW32__)
# ifndef AACENCAPI
#  define AACENCAPI __stdcall
# endif
#else
# ifndef AACENCAPI
#  define AACENCAPI
# endif
#endif

//��ʼ��
void	AACENCAPI	AAC_Enc_Init();

/*
	�򿪱���ͨ�������ر�����
	������
		nSampleRate��	������
		nChannels��		��Ƶͨ����
		nBitrate��		��������
		nBufSize��		�������ڲ������С
	���أ�0��ʧ��	�������ɹ�
*/
void*	AACENCAPI	AAC_Enc_Open(unsigned long nSampleRate, unsigned int nChannels,int nBitrate,int nBufSize);

/*
	����
	������
		handle��		ͨ�����
		pSrc��			PCM����ָ��
		nSrcLen��		PCM���ݴ�С
		pDst��			������ݵ�ַ
		nDstLen��		��������ݴ�С
	���أ�<0��ʧ��		1���ɹ�
		
*/
int		AACENCAPI	AAC_Enc_Encode(void* handle,unsigned char* pSrc,unsigned int nSrcLen,
								   unsigned char* pDst,unsigned int* nDstLen);

/*
	�رձ���ͨ����
	������
		handle��		����ͨ�����
	���أ�-1����������		1���ɹ�
		
*/
int		AACENCAPI	AAC_Enc_Close(void* handle);

//����ʼ��
void	AACENCAPI	AAC_Enc_DeInit();




#endif /* _DLL_AACENC_H_ */
