#include<stdio.h>
#include <string>
#include <sstream>
#include <fstream>
#include <windows.h>
#include "curl/curl.h"
#include "html/ParserDom.h"
#include "html/wincstring.h"
using namespace htmlcxx;

#if defined(_MSC_VER)
#define strcasecmp _stricmp
#endif
bool curlinit(std::string& res, const char* postdata = NULL);
int main()
{
	std::string res;
	std::string postdata;
	/*postdata ="__VIEWSTATE=%2FwEMDAwQAgAADgEMBQAMEAIAAA4FDAUBDBACDwEBBXZhbHVlAQExAA"
		"AMBQMMEAIPAQIAAAIBAAAADAUFDBACDA8BAQRUZXh0AQ8yMDE3MDcyODMwMDExMTEPAwEGb25ibHVyATRpZi"
		"h0aGlzLnZhbHVlPT0nJyl0aGlzLnZhbHVlPSfor7fovpPlhaXlj5fnkIbnvJblj7cnAQdvbmZvY3VzATRpZih"
		"0aGlzLnZhbHVlPT0n6K%2B36L6T5YWl5Y%2BX55CG57yW5Y%2B3Jyl0aGlzLnZhbHVlPScnAgAAARXor7fovpPlha"
		"Xlj5fnkIbnvJblj7cAAAwFCQwQAg8BAQVJdGVtcwUBAA4BDAUBDBACAAAOCgwFAQwQAhwaDVN5c3RlbS5TdHJpbmdLbX"
		"Njb3JsaWIsIFZlcnNpb249NC4wLjAuMCwgQ3VsdHVyZT1uZXV0cmFsLCBQdWJsaWNLZXlUb2tlbj1iNzdhNWM1NjE5MzRlMDg5AQIBAAAADA"
		"UDDBACHBsKAAECAwAAAAwFBQwQAhwbCgABATbmt7HlnLPluILli5jlr5%2FmtYvnu5jpmaLmnInpmZDlhazlj7jnoJTlj5HotYTliqnorqHliJIAAA"
		"wFBwwQAhwbCgABASTmt7HlnLPluILli5jlr5%2FmtYvnu5jpmaLmnInpmZDlhazlj7gAAAwFCQwQAhwbCgABASXmt7HlnLPluILnpo%2FnlLDljLrkuIrm"
		"raXkuK3ot68xMDQz5Y%2B3AAAMBQsMEAIcGwoAAQEG5p2o5b2kAAAMBQ0MEAIcGwoAAQEAAAAMBQ8MEAIcGwoAAQEY5LyB5Lia56CU56m25byA5Y%2BR6LWE5YqpAA"
		"AMBREMEAIcGwoAAQIQAAAADAUTDBACHBsKAAEBCeW%2BheivhOWuoQAADAULDBACDwEBCWlubmVyaHRtbAFcPHNwYW4%2BJmxhcXVvOzwvc3Bhbj48c3Bhbj4mbHNhcXVvOzwvc3B"
		"hbj48ZW0%2BMTwvZW0%2BPHNwYW4%2BJnJzYXF1bzs8L3NwYW4%2BPHNwYW4%2BJnJhcXVvOzwvc3Bhbj4AACCAAgABAAAA%2F%2F%2F%2F%2FwEAAAAAAAAABAEAAAB%2FU3lzdGVtLkNvbGx"
		"lY3Rpb25zLkdlbmVyaWMuTGlzdGAxW1tTeXN0ZW0uU3RyaW5nLCBtc2NvcmxpYiwgVmVyc2lvbj00LjAuMC4wLCBDdWx0dXJlPW5ldXRyYWwsIFB1YmxpY0tleVRva2VuPWI3N2E1YzU2MTkzNGUwODldXQMAAAAGX2l"
		"0ZW1zBV9zaXplCF92ZXJzaW9uBgAACAgJAgAAAAIAAAACAAAAEQIAAAAEAAAABgMAAAAGUGFnZU5vBgQAAAAHTWF4UGFnZQoKCwAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
		"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
		"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
		"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
		"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
		"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
		"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
		"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAACTsJuaHj2aS63H%2Ft4Pb1a"
		"HQf%2FZGCBl2mRm4xRJoToKAg%3D%3D&PageNo=1&MaxPage=1&";
	std::ostringstream mainstr; 
	mainstr <<"txtShenqingdanweimingcheng=";
	mainstr << 201707283001111;
	std::string endstr="&btnQuery=%E6%90%9C%E7%B4%A2..."
		 "&__EVENTVALIDATION=%2FwEdAAEAAAD%2F%2F%2F%2F%2FAQAAAAAAAAAPAQAAAAQAAAAI0PAKjvPBhpU7M6PgzEPnfAsAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
		"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAFtiFLdyntJNMoqEyH1RcWdtlJvEl8ldJ%2FX2NPR5MURy";
	postdata += mainstr.str();
	postdata += endstr;*/
	while (!curlinit(res, postdata.c_str()))
	{
		Sleep(4000);
	};
	//htmlcxx::HTML::ParserDom dom;
	//std::fstream htmlFileStream;
	//htmlFileStream.open("G:\Projects\Win32Project1\getthings\ft2.htm", std::ios::in); //打开指定HTML文件，这里你需要修改成自己的文件地址
	//std::istreambuf_iterator<char> fileBeg(htmlFileStream), fileEnd;
	//std::string html(fileBeg, fileEnd);
	//htmlFileStream.close();
	std::ofstream of;
	of.open("a.txt");
	of << res;
	of.close();
	setlocale(LC_ALL, ".OCP");
	 HTML::ParserDom parser;// 可以用来将html代码转换成dom树  
	tree<HTML::Node> dom = parser.parseTree(res);// 用来储存html各个节点  
	auto itr = dom.begin();
	itr->tagName();
	return 0;
}
WCHAR * Utf8ToUnicode(const CHAR * lpszStr)
{
	WCHAR * lpUnicode;
	int nLen;

	if (NULL == lpszStr)
		return NULL;

	nLen = ::MultiByteToWideChar(CP_UTF8, 0, lpszStr, -1, NULL, 0);
	if (0 == nLen)
		return NULL;

	lpUnicode = new WCHAR[nLen + 1];
	if (NULL == lpUnicode)
		return NULL;

	memset(lpUnicode, 0, sizeof(WCHAR) * (nLen + 1));
	nLen = ::MultiByteToWideChar(CP_UTF8, 0, lpszStr, -1, lpUnicode, nLen);
	if (0 == nLen)
	{
		delete[]lpUnicode;
		return NULL;
	}

	return lpUnicode;
}

static size_t OnWriteData(void* buffer, size_t size, size_t nmemb, void* lpVoid)
{
	std::string* str = dynamic_cast<std::string*>((std::string *)lpVoid);
	if (NULL == str || NULL == buffer)
	{
		return -1;
	}

	char* pData = (char*)buffer;
	str->append(pData, size * nmemb);
	return nmemb;
}
bool curlinit(std::string& res, const char* postdata /*= NULL*/)
{
	//CURLcode res;
	CURL* curl = curl_easy_init();
	if (NULL == curl)
	{
		printf("curl lib init error");
		return false;
	}

	//curl_setopt($, CURLOPT_HTTPHEADER, $header);     //curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);     curl_setopt($ch, CURLOPT_USERAGENT, 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10.12; rv:50.0) Gecko/20100101 Firefox/50.0');     curl_setopt($ch, CURLOPT_FOLLOWLOCATION, 1);     
	curl_easy_setopt(curl, CURLOPT_AUTOREFERER, 1); // 执行HTTP请求     curl_setopt($ch , CURLOPT_URL , $url);     $res = curl_exec($ch);   

	curl_easy_setopt(curl, CURLOPT_URL, "http://www.szsti.gov.cn/services/query/newdefault.aspx");

	//响应结果中保留头部信息
	if (false)
		curl_easy_setopt(curl, CURLOPT_HEADER, 1);
	curl_easy_setopt(curl, CURLOPT_COOKIEFILE, "");
	curl_easy_setopt(curl, CURLOPT_READFUNCTION, NULL);
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, OnWriteData);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&res);
	curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1);
	//设定为不验证证书和HOST
	//curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);
	//curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, false);

	//设置超时时间
	curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 10);
	curl_easy_setopt(curl, CURLOPT_TIMEOUT, 15);
	curl_easy_setopt(curl, CURLOPT_REFERER, "www.szsti.gov.cn");

	//设置代理
	//curl_easy_setopt(curl, CURLOPT_PROXY, "localhost:8080");
	//添加自定义头信息
	//if (headers != NULL)
	//{
	//	//LogInfo("http custom header: %s", headers);
	//	struct curl_slist *chunk = NULL;
	//	chunk = curl_slist_append(chunk, headers);
	//	curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);
	//}

	if (postdata != NULL)
	{
		//LogInfo("http post data: %s", postdata);
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postdata);
	}

	printf("http %s: url=%s, headers=%s, postdata=%s", false ? "get" : "post", "http://www.szsti.gov.cn/services/query/newdefault.aspx", /*headers != NULL ? headers :*/ "", postdata == NULL ? postdata : "");

	CURLcode rescode = curl_easy_perform(curl);
	bool bError = false;
	if (rescode == CURLE_OK)
	{
		int code;
		rescode = curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &code);
		if (code != 200 && code != 302)
		{
			bError = true;
			printf("http response code is not 200 or 302, code=%d", code);
		}
	}
	else
	{
		printf("http request error, error code = %d", rescode);
		bError = true;
	}
	if (res.compare("Internal Server Error") >= 0) bError = true;
	//printf(res.c_str());
	std::wstring resp;
	resp = Utf8ToUnicode(res.c_str());
	wprintf(resp.c_str());
	curl_easy_cleanup(curl);
	return !bError;
}