/**
 * sitemap.gs
 *
 * セル、D2以下の空白でないセルから sitemap.xml を作成し、
 * ユーザーへメールで送信するスクリプト
 *
 * @author ashikawa 2012/11/29
 */

var TARGET_COL = 4, // =D
    START_ROW  = 2,
    BASE_URL   = 'http://example.com/?q=';

/**
 * output ProjectDescription
 */
function help() {
  
  var str = "セル、D2以下の空白でないセルから sitemap.xml を作成し、"
          + "ユーザーへメールで送信するスクリプト。\n"
          + "\n"
          + "@author ashikawa 2012/11/29";
  
  Browser.msgBox(str);
}

/**
 * 実行ユーザーへメールを送信
 * @param {string} data メールに添付されるテキストデータ
 */
function mailSend(data) {

    var title     = 'SiteMap.xml',
        body      = 'SiteMap.xml',
        toAddress = Session.getUser().getEmail(),
        attach    = {
            fileName: 'sitemap.xml',
            mimeType: 'text/plain',
            content:  data
        },
        options   = {
            attachments: [attach]
        };

    MailApp.sendEmail(toAddress, title, body, options);
    Browser.msgBox('"' + toAddress + '"へ送信しました。');
}


/**
 * 対象要素からXMLを生成
 * @param {array.<string>} values 出力するURLの配列
 * @return string 生成したXML
 */
function buildSiteMapXml(values) {


  function formatUrl(str) {
    return BASE_URL + encodeURIComponent(str);
  }

  function formatXmlUrl(url) {
    
    var priority   = '0.5',
        changefreq = 'monthly';
    
    return '<url>\n'
         + '  <loc>' + url + '</loc>\n'
         + '  <priority>' + priority + '</priority>\n'
      /* + '  <lastmod>' + priority + '</lastmod>\n'*/
         + '  <changefreq>' + changefreq + '</changefreq>\n'
         + '</url>';
  }

  var value   = '',
      data    = '<?xml version="1.0" encoding="UTF-8"?>\n'
              + '<urlset xmlns="http://www.sitemaps.org/schemas/sitemap/0.9" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance">',
      l       = 0,
      i       = 0;

  for (i = 0, l = values.length; i < l; i++) {
    
    value = values[i];
    
    if (!value) {
      continue;
    }
    
    data += formatXmlUrl(formatUrl(value)) + "\n";
  }
  
  data += '</urlset>';
  
  return data;
}

/**
 * メイン処理
 * データ範囲決定,XML生成,メール送信
 */
function build() {

  var sheet     = SpreadsheetApp.getActiveSheet(),
      lastRow   = sheet.getLastRow(),
      range     = sheet.getRange(START_ROW, TARGET_COL, lastRow - START_ROW, 1),
      values    = range.getValues(),
      xml       = buildSiteMapXml(values);

  mailSend(xml);
}

function onOpen() {
  
  var sheet = SpreadsheetApp.getActiveSpreadsheet(),
      entries = [{
        name : "build",
        functionName : "build"
      },
      {
        name : "help",
        functionName : "help"
      }];
  
  sheet.addMenu("SiteMap.xml", entries);
}
