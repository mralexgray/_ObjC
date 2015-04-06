
Pod::Spec.new do |s|
  s.name            = "_ObjC"
  s.summary         = "A terse, 1:1 dialect of ObjC for Mac + iOS fat targets."
  s.version         = "1.0.0"
  s.description     = <<-DESC
                     AutoDescribe is like PHPs var_dump and print_r. 
                     Public and private properties are pretty printed.
                    DESC
  s.homepage        = "https://github.com/mralexgray/_ObjC"
  s.license         = 'WTFPL'
  s.author          = { "Alex Gray" => "alex@mrgray.com" }
  s.source          = { :git => "https://github.com/mralexgray/_ObjC.git", :tag => s.version.to_s }
  s.source_files    = '*.h'
  s.prepare_command = 'make'
end

