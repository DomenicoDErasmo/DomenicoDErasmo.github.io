class Student(object):
	def __init__(self, name, age, twitter_url=None, google_plus=None, youtube_channel=None):
		self.name = name
		self.age = age
		self.twitter_url = twitter_url
		self.google_plus = google_plus
 
	def __str__(self):
		# Override to print a readable string presentation of your object
		# below is a dynamic way of doing this without explicity constructing the string manually
		return ', '.join(['{key}={value}'.format(key=key, value=self.__dict__.get(key)) for key in self.__dict__])
 
student = Student(name='Jone', age=23, twitter_url='http://twitter.com/jone')
print (student)

