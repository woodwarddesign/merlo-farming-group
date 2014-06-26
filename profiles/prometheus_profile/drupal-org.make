; prometheus_profile make file for d.o. usage
core = "7.x"
api = "2"

; +++++ Modules +++++

projects[admin_menu][version] = "3.0-rc4"
projects[admin_menu][subdir] = "contrib"

projects[ctools][version] = "1.4"
projects[ctools][subdir] = "contrib"

projects[clean_markup][version] = "2.3"
projects[clean_markup][subdir] = "contrib"

projects[custom_breadcrumbs][version] = "2.0-alpha3"
projects[custom_breadcrumbs][subdir] = "contrib"

projects[date][version] = "2.7"
projects[date][subdir] = "contrib"

projects[profiler_builder][version] = "1.1"
projects[profiler_builder][subdir] = "contrib"

projects[features][version] = "2.0"
projects[features][subdir] = "contrib"

projects[uuid_features][version] = "1.0-alpha4"
projects[uuid_features][subdir] = "contrib"

projects[features_extra][version] = "1.0-beta1"
projects[features_extra][subdir] = "contrib"

projects[filefield_sources][version] = "1.9"
projects[filefield_sources][subdir] = "contrib"

projects[select_or_other][version] = "2.20"
projects[select_or_other][subdir] = "contrib"

projects[simplehtmldom][version] = "1.12"
projects[simplehtmldom][subdir] = "contrib"

projects[magic][version] = "1.5"
projects[magic][subdir] = "contrib"

projects[smartcrop][version] = "1.0-beta2"
projects[smartcrop][subdir] = "contrib"

projects[html5_tools][version] = "1.2"
projects[html5_tools][subdir] = "contrib"

projects[imagestyleflush][version] = "1.2"
projects[imagestyleflush][subdir] = "contrib"

projects[imce][version] = "1.8"
projects[imce][subdir] = "contrib"

projects[imce_mkdir][version] = "1.0"
projects[imce_mkdir][subdir] = "contrib"

projects[node_export][version] = "3.0-rc3"
projects[node_export][subdir] = "contrib"

projects[adaptive_image][version] = "1.4"
projects[adaptive_image][subdir] = "contrib"

projects[advuser][version] = "3.0-beta1"
projects[advuser][subdir] = "contrib"

projects[backup_migrate][version] = "2.8"
projects[backup_migrate][subdir] = "contrib"

projects[better_formats][version] = "1.0-beta1"
projects[better_formats][subdir] = "contrib"

projects[breakpoints][version] = "1.1"
projects[breakpoints][subdir] = "contrib"

projects[diff][version] = "3.2"
projects[diff][subdir] = "contrib"

projects[disable_messages][version] = "1.1"
projects[disable_messages][subdir] = "contrib"

projects[elements][version] = "1.4"
projects[elements][subdir] = "contrib"

projects[entity][version] = "1.3"
projects[entity][subdir] = "contrib"

projects[entity_autocomplete][version] = "1.0-beta3"
projects[entity_autocomplete][subdir] = "contrib"

projects[fitvids][version] = "1.14"
projects[fitvids][subdir] = "contrib"

projects[htmLawed][version] = "3.2"
projects[htmLawed][subdir] = "contrib"

projects[imagefield_focus][version] = "1.0"
projects[imagefield_focus][subdir] = "contrib"

projects[insert][version] = "1.3"
projects[insert][subdir] = "contrib"

projects[libraries][version] = "2.1"
projects[libraries][subdir] = "contrib"

projects[menu_attributes][version] = "1.0-rc2"
projects[menu_attributes][subdir] = "contrib"

projects[menu_block][version] = "2.4"
projects[menu_block][subdir] = "contrib"

projects[module_filter][version] = "1.8"
projects[module_filter][subdir] = "contrib"

projects[pathauto][version] = "1.2"
projects[pathauto][subdir] = "contrib"

projects[revisioning][version] = "1.8"
projects[revisioning][subdir] = "contrib"

projects[save_draft][version] = "1.4"
projects[save_draft][subdir] = "contrib"

projects[strongarm][version] = "2.0"
projects[strongarm][subdir] = "contrib"

projects[styleguide][version] = "1.1"
projects[styleguide][subdir] = "contrib"

projects[taxonomy_display][version] = "1.1"
projects[taxonomy_display][subdir] = "contrib"

projects[taxonomy_title][version] = "1.5"
projects[taxonomy_title][subdir] = "contrib"

projects[token][version] = "1.5"
projects[token][subdir] = "contrib"

projects[users_export][version] = "1.1"
projects[users_export][subdir] = "contrib"

projects[panels][version] = "3.3"
projects[panels][subdir] = "contrib"

projects[panels_style_collapsible][version] = "1.0"
projects[panels_style_collapsible][subdir] = "contrib"

projects[pantheon_api][version] = "1.0"
projects[pantheon_api][subdir] = "contrib"

projects[globalredirect][version] = "1.5"
projects[globalredirect][subdir] = "contrib"

projects[picture][version] = "1.2"
projects[picture][subdir] = "contrib"

projects[metatag][version] = "1.0-beta7"
projects[metatag][subdir] = "contrib"

projects[taxonomy_menu][version] = "1.4"
projects[taxonomy_menu][subdir] = "contrib"

projects[commentsblock][version] = "2.3"
projects[commentsblock][subdir] = "contrib"

projects[uuid][version] = "1.0-alpha5"
projects[uuid][subdir] = "contrib"

projects[imce_wysiwyg][version] = "1.0"
projects[imce_wysiwyg][subdir] = "contrib"

projects[jquery_update][version] = "2.3"
projects[jquery_update][subdir] = "contrib"

projects[options_element][version] = "1.10"
projects[options_element][subdir] = "contrib"

projects[wysiwyg][version] = "2.2"
projects[wysiwyg][subdir] = "contrib"

projects[wysiwyg_spellcheck][version] = "1.1"
projects[wysiwyg_spellcheck][subdir] = "contrib"

projects[variable][version] = "2.3"
projects[variable][subdir] = "contrib"

projects[semanticviews][version] = "1.x-dev"
projects[semanticviews][subdir] = "contrib"

projects[views][version] = "3.8"
projects[views][subdir] = "contrib"

projects[views_responsive_grid][version] = "1.3"
projects[views_responsive_grid][subdir] = "contrib"

projects[xmlsitemap][version] = "2.0-rc2"
projects[xmlsitemap][subdir] = "contrib"

; +++++ Libraries +++++

; CKEditor
libraries[ckeditor][directory_name] = "ckeditor"
libraries[ckeditor][type] = "library"
libraries[ckeditor][destination] = "libraries"
libraries[ckeditor][download][type] = "get"
libraries[ckeditor][download][url] = "http://download.cksource.com/CKEditor/CKEditor/CKEditor%203.6.6.1/ckeditor_3.6.6.1.tar.gz"

; FitVids
libraries[fitvids][directory_name] = "fitvids"
libraries[fitvids][type] = "library"
libraries[fitvids][destination] = "libraries"
libraries[fitvids][download][type] = "get"
libraries[fitvids][download][url] = "https://raw.github.com/davatron5000/FitVids.js/master/jquery.fitvids.js"

