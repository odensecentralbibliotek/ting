api = 2
core = 7.x

; Contrib

projects[nanosoap][subdir] = contrib
projects[nanosoap][version] = "1.0"
projects[nanosoap][patch][1914526] = https://drupal.org/files/nanosoap-ns-header-config-1914526-1.patch

projects[blackhole][subdir] = contrib
projects[blackhole][version] = "1.1"
;projects[virtual_field][subdir] = contrib
;projects[virtual_field][version] = "1.0"

; Libraries

libraries[ting-client][download][type] = "git"
libraries[ting-client][download][url] = "https://github.com/odensecentralbibliotek/ting-client.git"
libraries[ting-client][destination] = "modules/ting/lib"

; Ding 2 modules

projects[ding_entity][type] = "module"
projects[ding_entity][download][type] = "git"
projects[ding_entity][download][url] = "git@github.com:ding2tal/ding_entity.git"
projects[ding_entity][download][branch] = "development"
