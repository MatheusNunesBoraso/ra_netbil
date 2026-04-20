Pod::Spec.new do |s|
  s.name             = 'easyar_flutter'
  s.version          = '0.0.1'
  s.summary          = 'EasyAR Sense SDK wrapper for Flutter (Netbil).'
  s.description      = <<-DESC
Local Flutter plugin wrapping EasyAR Sense 4.8 for the RA Netbil app.
  DESC
  s.homepage         = 'https://netbil.com.br'
  s.license          = { :type => 'Proprietary', :text => 'Netbil internal use.' }
  s.author           = { 'Netbil' => 'developer@netbil.com.br' }
  s.source           = { :path => '.' }
  s.source_files     = 'Classes/**/*'
  s.public_header_files = 'Classes/**/*.h'
  s.dependency 'Flutter'
  s.platform         = :ios, '12.0'
  s.vendored_frameworks = 'easyar.xcframework'
  s.pod_target_xcconfig = {
    'DEFINES_MODULE' => 'YES',
    'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'i386'
  }
  s.swift_version = '5.0'
end
