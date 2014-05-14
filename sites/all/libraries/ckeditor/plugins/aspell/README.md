When FCKeditor became CKEditor, it no longer supported Aspell, but there is still interest in using Aspell with CKEditor. [A user by the name of "keilaron" in the CKEditor support forums](http://ckeditor.com/forums/CKEditor-3.x/Interest-aspellspellerpages-plug-for-CKE-3) ported the FCK 2 spellerpages feature as a plugin for CKEditor 3.x back in September 2009. Unfortunately, that version does not work with CKEditor 4. 

I've taken the *modified-for-ckeditor3-version* and tweaked it so it will work with CKEditor 4. I've incorporated all of the fixes posted on the aforementioned forum thread (I think I got them all). As I use this plugin within a ColdFusion environment, I did not modify the PHP script. So if you want to use PHP, the script might need some tweaking.

I have included the original *modified-for-ckeditor3-version* as a 7z archive for backup/posterity. You can find the original in the forum thread linked above.

Also, if you Google (Bing? DuckDuckGo?) "CKEditor 4 Aspell", you might come across [this link](http://itsm-demo.otrs.com/otrs-web/js/thirdparty/ckeditor-4.2/plugins/aspell/). Unfortunately the author of this port says that it is a "very customized version of the plugin [for] our product OTRS". The good news is that the OTRS port is also based on the *modified-for-ckeditor3-version* port. So we're all going in the same direction.
