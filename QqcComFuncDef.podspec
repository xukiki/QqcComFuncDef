Pod::Spec.new do |s|

  s.license      = "MIT"
  s.author       = { "qqc" => "20599378@qq.com" }
  s.platform     = :ios, "8.0"
  s.requires_arc  = true

  s.name         = "QqcComFuncDef"
  s.version      = "1.0.11"
  s.summary      = "QqcComFuncDef"
  s.homepage     = "https://github.com/xukiki/QqcComFuncDef"
  s.source       = { :git => "https://github.com/xukiki/QqcComFuncDef.git", :tag => "#{s.version}" }
  
  s.source_files  = ["QqcComFuncDef/*.{h,m}"]

end
